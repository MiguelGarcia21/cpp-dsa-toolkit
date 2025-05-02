#pragma once
#include "common.h"

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;  // Use the central Node class
    Node<T>* tail;
    int listLength;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void addFront(T data);
    void addEnd(T data);
    void addAt(T data, int position);
    void deleteAt(int position);
    void printForward() const;
    void printBackward() const;
    int find(T data) const;
};

#include "../src/DoublyLinkedList.tpp"  // Include the template implementation