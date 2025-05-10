#pragma once
#include "../include/Heap.h"

template<typename T>
Heap<T>::Heap(HeapType t) : type(t) {}

template<typename T>
int Heap<T>::size() const {
    return static_cast<int>(vect.size()) - 1;
}

template<typename T>
bool Heap<T>::isEmpty() const {
    return size() == 0;
}

template<typename T>
const T& Heap<T>::top() const {
    if (isEmpty()) throw std::out_of_range("Heap is empty!");
    return vect[1];
}

template<typename T>
bool Heap<T>::compare(const T& a, const T& b) const {
    return type == HeapType::MAX ? a > b : a < b;
}

template<typename T>
void Heap<T>::insertItem(const T& val) {
    vect.push_back(val);
    shiftUp(size());
}

template<typename T>
void Heap<T>::shiftUp(int i) {
    while (i > 1 && compare(vect[i], vect[parent(i)])) {
        std::swap(vect[i], vect[parent(i)]);
        i = parent(i);
    }
}

template<typename T>
void Heap<T>::shiftDown(int i) {
    int swapId = i;
    int l = left(i), r = right(i);

    if (l <= size() && compare(vect[l], vect[swapId]))
        swapId = l;
    if (r <= size() && compare(vect[r], vect[swapId]))
        swapId = r;

    if (swapId != i) {
        std::swap(vect[i], vect[swapId]);
        shiftDown(swapId);
    }
}

template<typename T>
T Heap<T>::extractTop() {
    if (isEmpty()) throw std::out_of_range("Heap is empty!");

    T topVal = vect[1];
    vect[1] = vect.back();
    vect.pop_back();
    if (!isEmpty()) shiftDown(1);
    return topVal;
}

template<typename T>
void Heap<T>::deleteItem(const T& val) {
    int index = -1;
    for (int i = 1; i <= size(); ++i) {
        if (vect[i] == val) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        std::cerr << "Value not found in heap.\n";
        return;
    }

    vect[index] = vect.back();
    vect.pop_back();

    if (index <= size()) {
        shiftDown(index);
        shiftUp(index);
    }
}

template<typename T>
void Heap<T>::heapify(const std::vector<T>& data) {
    vect = { T() }; // Reset with dummy element for 1-based indexing
    vect.insert(vect.end(), data.begin(), data.end());

    for (int i = size() / 2; i >= 1; --i)
        shiftDown(i);
}

template<typename T>
void Heap<T>::printHeap() const {
    std::cout << "Heap: ";
    for (int i = 1; i <= size(); ++i)
        std::cout << vect[i] << " ";
    std::cout << '\n';
}