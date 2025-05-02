#pragma once
#include "../include/LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), listLength(0) {}

template <typename T>
LinkedList<T>::~LinkedList(){
    Node* current = head;
    while(current != nullptr){
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
LinkedList<T>::Node::Node(T data) : data(data), next(nullptr){}

template <typename T>
void LinkedList<T>::addFront(T data){
    Node* newNode = new Node(data);
    if(!head){
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    listLength++;
}

template <typename T>
void LinkedList<T>::addEnd(T data){
    Node* newNode = new Node(data);
    if(!tail){
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    listLength++;
}

template <typename T>
void LinkedList<T>::addAt(T data, int position){
    if(position < 0 || position > listLength){
        std::cout << "Invalid Position\n";
        return; //failed
    }

    if(position == 0){
        addFront(data);
        return;
    }
    if(position == listLength){
        addEnd(data);
        return;
    }

    Node* current = head;
    for (int i = 0; i < position - 1; ++i){
        current = current->next;
    }

    Node* newNode = new Node(data);
    newNode->next = current->next;
    current->next = newNode;
    listLength++;
}

template <typename T>
void LinkedList<T>::printList() const{
    Node* current = head;

    while(current){
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "Null\n";
}

template <typename T>
void LinkedList<T>::deleteAt(int position){
    if(position < 0 || position >= listLength){
        std::cout << "Invalid Position\n";
        return;
    }

    Node* temp;
    if(position == 0){
        temp = head;
        head = head->next;
        if(!head){
            tail = nullptr;
        }
    } else {
        Node* prev = head;

        for (int i = 0; i < position - 1; ++i){
            prev = prev->next;
        }

        temp = prev->next;
        prev->next = temp->next;
        if(!prev->next){
            tail = prev;
        }
    }

    delete temp;
    listLength--;
}

template <typename T>
int LinkedList<T>::find(T data) const {
    Node* current = head;
    int index = 0;

    while(current){
        if(current->data == data){
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}
