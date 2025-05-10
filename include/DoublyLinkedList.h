#pragma once
#include "common.h"

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t listLength;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void addFront(const T& data);
    void addEnd(const T& data);
    void addAt(const T& data, size_t position);
    void deleteAt(size_t position);
    
    bool isEmpty() const { return listLength == 0; }
    size_t length() const { return listLength; }
    
    int find(const T& data) const;
    void printForward() const;
    void printBackward() const;
    void reverse();
};

#include "../src/DoublyLinkedList.tpp" 