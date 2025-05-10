#pragma once
#include "common.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int listLength;

public:
    LinkedList();
    ~LinkedList();

    void addFront(T data);
    void addEnd(T data);
    void addAt(T data, int position);
    void deleteAt(int position);
    int find(T data) const;
    void printList() const;

    int length() const { return listLength; }
    bool isEmpty() const { return listLength == 0; }
};

#include "../src/LinkedList.tpp"