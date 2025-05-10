#pragma once
#include "../include/DoublyLinkedList.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), listLength(0) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void DoublyLinkedList<T>::addFront(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    listLength++;
}

template <typename T>
void DoublyLinkedList<T>::addEnd(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    listLength++;
}

template <typename T>
void DoublyLinkedList<T>::addAt(const T& data, size_t position) {
    if (position > listLength) {
        throw std::out_of_range("Position out of range");
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
    for (size_t i = 0; i < position - 1; ++i) {
        current = current->next;
    }

    Node<T>* newNode = new Node<T>(data);
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
    listLength++;
}

template <typename T>
void DoublyLinkedList<T>::deleteAt(size_t position) {
    if (position >= listLength) {
        throw std::out_of_range("Position out of range");
    }

    Node<T>* toDelete;

    if (position == 0) {
        toDelete = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
    } else {
        toDelete = head;
        for (size_t i = 0; i < position; ++i) {
            toDelete = toDelete->next;
        }

        toDelete->prev->next = toDelete->next;
        if (toDelete->next) {
            toDelete->next->prev = toDelete->prev;
        } else {
            tail = toDelete->prev;
        }
    }

    delete toDelete;
    listLength--;
}

template <typename T>
void DoublyLinkedList<T>::reverse() {
    Node<T>* current = head;
    Node<T>* temp = nullptr;
    tail = head;
    
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    if (temp) {
        head = temp->prev;
    }
}

template <typename T>
int DoublyLinkedList<T>::find(const T& data) const {
    Node<T>* current = head;
    int index = 0;
    while (current) {
        if (current->data == data) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

template <typename T>
void DoublyLinkedList<T>::printForward() const {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data;
        if (current->next) std::cout << " <-> ";
        current = current->next;
    }
    std::cout << " -> NULL\n";
}

template <typename T>
void DoublyLinkedList<T>::printBackward() const {
    Node<T>* current = tail;
    while (current) {
        std::cout << current->data;
        if (current->prev) std::cout << " <-> ";
        current = current->prev;
    }
    std::cout << " -> NULL\n";
}