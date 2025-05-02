#pragma once
#include "common.h"

enum class HeapType {
    MAX,
    MIN
};

template<typename T>
class Heap {
private:
    std::vector<T> vect = { T() }; // 1-based indexing
    HeapType type;

    int parent(int i) const { return i >> 1; }
    int left(int i) const { return i << 1; }
    int right(int i) const { return (i << 1) + 1; }

    bool compare(const T& a, const T& b) const;

public:
    Heap(HeapType t = HeapType::MAX);

    int size() const;
    bool isEmpty() const;
    T top() const;

    void insertItem(const T& value);
    void shiftUp(int i);
    T extractTop();
    void shiftDown(int i);
    void deleteItem(const T& val);
    void heapify(const std::vector<T>& data);
    void printHeap() const;
};