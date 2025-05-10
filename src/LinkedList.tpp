#pragma once
#include "../include/LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), listLength(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void LinkedList<T>::addFront(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
    if (!tail) tail = newNode;
    listLength++;
}

template <typename T>
void LinkedList<T>::addEnd(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    listLength++;
}

template <typename T>
void LinkedList<T>::addAt(T data, int position) {
    if (position < 0 || position > listLength) {
        throw std::out_of_range("Invalid Position");
    }

    if (position == 0) {
        addFront(data);
        return;
    }
    if (position == listLength) {
        addEnd(data);
        return;
    }

    Node<T>* current = head;
    for (int i = 0; i < position - 1; ++i) {
        current = current->next;
    }

    Node<T>* newNode = new Node<T>(data);
    newNode->next = current->next;
    current->next = newNode;
    listLength++;
}

template <typename T>
void LinkedList<T>::deleteAt(int position) {
    if (position < 0 || position >= listLength) {
        throw std::out_of_range("Invalid Position");
    }

    Node<T>* temp;
    if (position == 0) {
        temp = head;
        head = head->next;
        if (!head) tail = nullptr;
    } else {
        Node<T>* prev = head;
        for (int i = 0; i < position - 1; ++i) {
            prev = prev->next;
        }
        temp = prev->next;
        prev->next = temp->next;
        if (!prev->next) tail = prev;
    }

    delete temp;
    listLength--;
}

template <typename T>
int LinkedList<T>::find(T data) const {
    Node<T>* current = head;
    int index = 0;

    while (current) {
        if (current->data == data) return index;
        current = current->next;
        index++;
    }
    return -1;
}

template <typename T>
void LinkedList<T>::printList() const {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "Null\n";
}