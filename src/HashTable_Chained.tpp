#pragma once
#include "../include/HashTable_Chained.h"

template <typename K, typename V>
size_t HashTable_Chained<K, V>::hashFunction(const K& key) const {
    return std::hash<K>{}(key) % DEFAULT_CAPACITY;
}

template <typename K, typename V>
void HashTable_Chained<K, V>::insert(const K& key, const V& value) {
    size_t hashValue = hashFunction(key);
    auto& bucket = table[hashValue];

    for (auto& pair : bucket) {
        if (pair.first == key) {
            pair.second.push_back(value);
            itemCount++;
            return;
        }
    }

    bucket.emplace_back(key, std::list<V>{value});
    itemCount++;
}

template <typename K, typename V>
bool HashTable_Chained<K, V>::remove(const K& key, const V& value) {
    size_t hashValue = hashFunction(key);
    auto& bucket = table[hashValue];

    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (it->first == key) {
            auto& values = it->second;
            auto valIt = std::find(values.begin(), values.end(), value);
            
            if (valIt != values.end()) {
                values.erase(valIt);
                itemCount--;
                
                if (values.empty()) {
                    bucket.erase(it);
                }
                return true;
            }
            return false;
        }
    }
    return false;
}

template <typename K, typename V>
bool HashTable_Chained<K, V>::removeKey(const K& key) {
    size_t hashValue = hashFunction(key);
    auto& bucket = table[hashValue];

    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (it->first == key) {
            itemCount -= it->second.size();
            bucket.erase(it);
            return true;
        }
    }
    return false;
}

template <typename K, typename V>
std::list<V> HashTable_Chained<K, V>::get(const K& key) const {
    size_t hashValue = hashFunction(key);
    const auto& bucket = table[hashValue];

    for (const auto& pair : bucket) {
        if (pair.first == key) {
            return pair.second;
        }
    }
    return {};
}

template <typename K, typename V>
bool HashTable_Chained<K, V>::contains(const K& key) const {
    size_t hashValue = hashFunction(key);
    const auto& bucket = table[hashValue];

    for (const auto& pair : bucket) {
        if (pair.first == key) {
            return true;
        }
    }
    return false;
}

template <typename K, typename V>
void HashTable_Chained<K, V>::clear() {
    for (size_t i = 0; i < DEFAULT_CAPACITY; ++i) {
        table[i].clear();
    }
    itemCount = 0;
}

template <typename K, typename V>
void HashTable_Chained<K, V>::print() const {
    for (size_t i = 0; i < DEFAULT_CAPACITY; ++i) {
        if (!table[i].empty()) {
            std::cout << "Bucket " << i << ":\n";
            for (const auto& pair : table[i]) {
                std::cout << "  Key: " << pair.first << " -> [";
                for (const auto& val : pair.second) {
                    std::cout << val << ", ";
                }
                std::cout << "]\n";
            }
        }
    }
}

template <typename K, typename V>
void HashTable_Chained<K, V>::rehash(size_t newCapacity) {
    // TODO
    throw std::runtime_error("Rehash not implemented for fixed-size table");
}