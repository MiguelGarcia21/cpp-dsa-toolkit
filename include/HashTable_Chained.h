#pragma once
#include "common.h"

template <typename K, typename V>
class HashTable_Chained {
private:
    static const size_t DEFAULT_CAPACITY = 10;
    std::list<std::pair<K, std::list<V>>> table[DEFAULT_CAPACITY];
    size_t itemCount = 0;

public:
    HashTable_Chained() = default;
    ~HashTable_Chained() = default;

    bool isEmpty() const { return itemCount == 0; }
    size_t size() const { return itemCount; }
    size_t capacity() const { return DEFAULT_CAPACITY; }
    
    size_t hashFunction(const K& key) const;
    void insert(const K& key, const V& value);
    bool remove(const K& key, const V& value);
    bool removeKey(const K& key);
    std::list<V> get(const K& key) const;
    bool contains(const K& key) const;
    
    void clear();
    void print() const;
    
    void rehash(size_t newCapacity);
};

#include "../src/HashTable_Chained.tpp" 