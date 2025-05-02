#pragma once
#include "common.h"

template <typename KeyType, typename ValueType>
class HashTable {
private:
    static const int hashGroups = 10;
    std::list<Node<KeyType, ValueType>> table[hashGroups];

public:
    bool isEmpty() const;
    int hashFunction(KeyType key) const;
    void insertItem(KeyType key, ValueType value);
    void removeItem(KeyType key);
    ValueType searchTable(KeyType key) const;
    void printTable() const;
};

template <typename KeyType, typename ValueType>
class Node {
public:
    KeyType key;
    ValueType value;
    Node(KeyType k, ValueType v) : key(k), value(v) {}
};