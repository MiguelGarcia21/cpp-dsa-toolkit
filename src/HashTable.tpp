#pragma once
#include "../include/HashTable.h"

template <typename KeyType, typename ValueType>
bool HashTable<KeyType, ValueType>::isEmpty() const {
    int sum = 0;
    for (int i = 0; i < hashGroups; i++) {
        sum += table[i].size();
    }
    return sum == 0;
}

template <typename KeyType, typename ValueType>
int HashTable<KeyType, ValueType>::hashFunction(KeyType key) const {
    return key % hashGroups;
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::insertItem(KeyType key, ValueType value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    bool keyExist = false;

    for (auto it = begin(cell); it != end(cell); it++) {
        if(it->key == key) {
            keyExist = true;
            it->value = value;
            std::cout << "Value replaced" << std::endl;
            break;
        }
    }

    if (!keyExist) {
        cell.emplace_back(key, value);
        std::cout << "Value inserted" << std::endl;
    }
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::removeItem(KeyType key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    bool keyExist = false;

    for (auto it = begin(cell); it != end(cell); it++) {
        if (it->key == key) {
            keyExist = true;
            it = cell.erase(it);
            std::cout << "Value deleted" << std::endl;
            break;
        }
    }

    if (!keyExist) {
        std::cout << "Key not found" << std::endl;
    }
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::printTable() const {
    for (int i = 0; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;
        for (auto it = table[i].begin(); it != table[i].end(); it++) {
            std::cout << "Key: " << it->key << " Value: " << it->value << std::endl;
        }
    }
}

template <typename KeyType, typename ValueType>
ValueType HashTable<KeyType, ValueType>::searchTable(KeyType key) const {
    int hashValue = hashFunction(key);
    const auto& cell = table[hashValue];

    for (const auto& pair : cell) {
        if (pair.key == key) {
            return pair.value;
        }
    }

    return "Not found";
}