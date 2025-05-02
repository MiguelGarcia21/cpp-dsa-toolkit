#pragma once
#include "../include/Node.h"

template <typename T>
Node<T>::Node(T data) : data(data), next(nullptr), prev(nullptr), left(nullptr), right(nullptr), parent(nullptr) {}

template <typename T>
Node<T>::Node(T data, Node* left, Node* right, Node* parent) 
    : data(data), next(nullptr), prev(nullptr), left(left), right(right), parent(parent) {}