#pragma once
#include "common.h"

template <typename KeyType, typename ValueType>
class HashTable {
private:
    static const size_t DEFAULT_CAPACITY = 10;
    std::list<std::pair<KeyType, ValueType>> table[DEFAULT_CAPACITY];
    size_t itemCount = 0;

    bool keyExists(size_t hashValue, const KeyType& key) const;

public:
    HashTable() = default;
    ~HashTable() = default;

    bool isEmpty() const { return itemCount == 0; }
    size_t size() const { return itemCount; }
    size_t capacity() const { return DEFAULT_CAPACITY; }

    size_t hashFunction(const KeyType& key) const;
    void insert(const KeyType& key, const ValueType& value);
    bool remove(const KeyType& key);
    ValueType get(const KeyType& key) const;
    bool contains(const KeyType& key) const;

    void clear();
    void print() const;
};

#include "../src/HashTable.tpp"