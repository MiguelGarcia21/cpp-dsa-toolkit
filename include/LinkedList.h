#pragma once
#include "common.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;  // Use the central Node class
    Node<T>* tail;
    int listLength;

public:
    LinkedList();
    ~LinkedList();

    void addFront(T data);
    void addEnd(T data);
    void addAt(T data, int position);
    void printList() const;
    void deleteAt(int position);
    int find(T data) const;
};

#include "../src/LinkedList.tpp"  // Include the template implementation
