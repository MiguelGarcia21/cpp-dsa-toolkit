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

    Node(T data);

    Node(T data, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr);
};