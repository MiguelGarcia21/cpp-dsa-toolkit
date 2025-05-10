#pragma once
#include "common.h"

template <typename T>
class Node {
public:
    T data;
    Node* next; 
    Node* prev;  
    Node* left;
    Node* right;
    Node* parent;

    explicit Node(T data);

    explicit Node(T data, Node* left);

    explicit Node(T data, Node* left, Node* right);

    explicit Node(T data, Node* left, Node* right, Node* parent);
};

#include "../src/Node.tpp" 