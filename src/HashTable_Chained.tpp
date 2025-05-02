#pragma once
#include "../include/HashTable_Chained.h"

template <typename K, typename V>
bool HashTable_Chained<K, V>::isEmpty() const {
    int sum = 0;
    for (int i = 0; i < hashGroups; i++) {
        sum += table[i].size();
    }
    return sum == 0;
}

template <typename K, typename V>
int HashTable_Chained<K, V>::hashFunction(const K& key) const {
    std::hash<K> hasher;
    return hasher(key) % hashGroups;
}

template <typename K, typename V>
void HashTable_Chained<K, V>::insertItem(const K& key, const V& value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];

    for (auto& pair : cell) {
        if (pair.first == key) {
            pair.second.push_back(value);
            std::cout << "Value added to existing key\n";
            return;
        }
    }

    cell.emplace_back(key, std::list<V>{value});
    std::cout << "New key with value inserted\n";
}

template <typename K, typename V>
void HashTable_Chained<K, V>::removeItem(const K& key, const V& value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];

    for (auto it = cell.begin(); it != cell.end(); ++it) {
        if (it->first == key) {
            auto& valList = it->second;
            valList.remove(value);
            if (valList.empty()) {
                cell.erase(it);
                std::cout << "Key and value removed (no more values left)\n";
            } else {
                std::cout << "Value removed from key\n";
            }
            return;
        }
    }

    std::cout << "Key not found\n";
}

template <typename K, typename V>
std::list<V> HashTable_Chained<K, V>::searchTable(const K& key) const {
    int hashValue = hashFunction(key);
    const auto& cell = table[hashValue];

    for (const auto& pair : cell) {
        if (pair.first == key) {
            return pair.second;
        }
    }

    return {};
}

template <typename K, typename V>
void HashTable_Chained<K, V>::printTable() const {
    for (int i = 0; i < hashGroups; ++i) {
        for (const auto& pair : table[i]) {
            std::cout << "Key: " << pair.first << " -> ";
            for (const auto& val : pair.second) {
                std::cout << val << ", ";
            }
            std::cout << "\n";
        }
    }
}