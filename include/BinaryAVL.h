#pragma once
#include "common.h"

template <typename T>
class AVLTree {
private:
    Node<T>* root;

    int height(Node<T>* node) const;
    int balanceFactor(Node<T>* node) const;
    Node<T>* rotateLeft(Node<T>* x);
    Node<T>* rotateRight(Node<T>* y);
    Node<T>* insert(Node<T>* node, T data);
    Node<T>* deleteNode(Node<T>* node, T data);
    void inorder(Node<T>* node) const;

public:
    AVLTree();
    ~AVLTree();

    void insert(T data);
    void deleteNode(T data);
    void print() const;
};

#include "../src/BinaryAVL.tpp"  // Include the template implementation
