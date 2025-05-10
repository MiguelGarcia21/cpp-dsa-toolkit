#pragma once
#include "../include/HashTable.h"

template <typename KeyType, typename ValueType>
bool HashTable<KeyType, ValueType>::keyExists(size_t hashValue, const KeyType& key) const {
    const auto& bucket = table[hashValue];
    for (const auto& pair : bucket) {
        if (pair.first == key) {
            return true;
        }
    }
    return false;
}

template <typename KeyType, typename ValueType>
size_t HashTable<KeyType, ValueType>::hashFunction(const KeyType& key) const {
    return std::hash<KeyType>{}(key) % DEFAULT_CAPACITY;
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value) {
    size_t hashValue = hashFunction(key);
    auto& bucket = table[hashValue];

    for (auto& pair : bucket) {
        if (pair.first == key) {
            pair.second = value;
            return;
        }
    }

    bucket.emplace_back(key, value);
    itemCount++;
}

template <typename KeyType, typename ValueType>
bool HashTable<KeyType, ValueType>::remove(const KeyType& key) {
    size_t hashValue = hashFunction(key);
    auto& bucket = table[hashValue];

    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (it->first == key) {
            bucket.erase(it);
            itemCount--;
            return true;
        }
    }
    return false;
}

template <typename KeyType, typename ValueType>
ValueType HashTable<KeyType, ValueType>::get(const KeyType& key) const {
    size_t hashValue = hashFunction(key);
    const auto& bucket = table[hashValue];

    for (const auto& pair : bucket) {
        if (pair.first == key) {
            return pair.second;
        }
    }
    throw std::out_of_range("Key not found");
}

template <typename KeyType, typename ValueType>
bool HashTable<KeyType, ValueType>::contains(const KeyType& key) const {
    return keyExists(hashFunction(key), key);
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::clear() {
    for (size_t i = 0; i < DEFAULT_CAPACITY; ++i) {
        table[i].clear();
    }
    itemCount = 0;
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::print() const {
    for (size_t i = 0; i < DEFAULT_CAPACITY; ++i) {
        if (!table[i].empty()) {
            std::cout << "Bucket " << i << ":\n";
            for (const auto& pair : table[i]) {
                std::cout << "  Key: " << pair.first << " -> Value: " << pair.second << "\n";
            }
        }
    }
}