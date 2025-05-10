#pragma once
#include "common.h"
#include <vector>
#include <stdexcept>
#include <iostream>

enum class HeapType {
    MAX,
    MIN
};

template<typename T>
class Heap {
private:
    std::vector<T> vect = { T() };
    HeapType type;

    int parent(int i) const { return i / 2; }
    int left(int i) const { return i * 2; }
    int right(int i) const { return i * 2 + 1; }

    bool compare(const T& a, const T& b) const;

public:
    explicit Heap(HeapType t = HeapType::MAX);

    int size() const;
    bool isEmpty() const;
    const T& top() const;

    void insertItem(const T& value);
    T extractTop();
    void deleteItem(const T& val);
    void heapify(const std::vector<T>& data);

    void shiftUp(int i);
    void shiftDown(int i);
    void printHeap() const;
};

#include "../src/Heap.tpp"