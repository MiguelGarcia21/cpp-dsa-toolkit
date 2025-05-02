#pragma once
#include "common.h"

template <typename K, typename V>
class HashTable_Chained {
    static const int hashGroups = 10;
    std::list<std::pair<K, std::list<V>>> table[hashGroups];

public:
    bool isEmpty() const;
    int hashFunction(const K& key) const;
    void insertItem(const K& key, const V& value);
    void removeItem(const K& key, const V& value);
    std::list<V> searchTable(const K& key) const;
    void printTable() const;
};