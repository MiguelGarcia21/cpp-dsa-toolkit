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

    // Simple constructor with just data
    explicit Node(T data);

    // Constructor with data and one child (left)
    explicit Node(T data, Node* left);

    // Constructor with data and two children
    explicit Node(T data, Node* left, Node* right);

    // Full constructor with all relationships
    explicit Node(T data, Node* left, Node* right, Node* parent);
};

#include "../src/Node.tpp" 