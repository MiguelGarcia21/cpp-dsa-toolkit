#pragma once
#include "../include/BinaryTree.h"

// Constructor
template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

// Destructor
template <typename T>
BinaryTree<T>::~BinaryTree() {
    // Add logic to delete all nodes if necessary
    // for now, assuming that memory will be managed elsewhere.
}

template <typename T>
void BinaryTree<T>::insert(T data) {
    Node<T>* newNode = new Node<T>(data);

    if (!root) {
        root = newNode;
        return;
    }

    Node<T>* current = root;
    Node<T>* parent = nullptr;

    while (current) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

template <typename T>
void BinaryTree<T>::deleteNode(T data) {
    // Implement delete logic if needed
}

template <typename T>
void BinaryTree<T>::dfs() const {
    dfs(root);
}

template <typename T>
void BinaryTree<T>::dfs(Node<T>* node) const {
    if (node) {
        std::cout << node->data << " ";
        dfs(node->left);
        dfs(node->right);
    }
}

template <typename T>
void BinaryTree<T>::bfs() const {
    bfs(root);
}

template <typename T>
void BinaryTree<T>::bfs(Node<T>* node) const {
    if (!node) return;

    std::queue<Node<T>*> q;
    q.push(node);

    while (!q.empty()) {
        Node<T>* current = q.front();
        q.pop();
        std::cout << current->data << " "; //logic to process

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

template <typename T>
void BinaryTree<T>::printDfs() const {
    dfs();
}

template <typename T>
void BinaryTree<T>::printBfs() const {
    dfs();
}
