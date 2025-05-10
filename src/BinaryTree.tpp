#pragma once
#include "../include/BinaryTree.h"

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
BinaryTree<T>::~BinaryTree() {
    clear(root);
}

template <typename T>
void BinaryTree<T>::clear(Node<T>* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
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

    newNode->parent = parent;
    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

template <typename T>
bool BinaryTree<T>::search(T data) const {
    Node<T>* current = root;
    while (current) {
        if (data == current->data) return true;
        current = data < current->data ? current->left : current->right;
    }
    return false;
}

template <typename T>
void BinaryTree<T>::deleteNode(T data) {
    Node<T>* parent = nullptr;
    Node<T>* current = root;

    while (current && current->data != data) {
        parent = current;
        current = data < current->data ? current->left : current->right;
    }
    
    if (!current) return;
    
    if (!current->left && !current->right) {
        if (current != root) {
            if (parent->left == current) parent->left = nullptr;
            else parent->right = nullptr;
        } else {
            root = nullptr;
        }
        delete current;
    }
    
    else if (current->left && current->right) { // Case when node has two children
        Node<T>* successor = current->right;
        while (successor->left) successor = successor->left;
        
        T temp = successor->data;
        deleteNode(temp);
        current->data = temp;
    }
    
    else {
        Node<T>* child = current->left ? current->left : current->right; // Case when node has one child
        
        if (current != root) {
            if (current == parent->left) parent->left = child;
            else parent->right = child;
        } else {
            root = child;
        }
        child->parent = parent;
        delete current;
    }
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
void BinaryTree<T>::dfs() const {
    dfs(root);
}

template <typename T>
void BinaryTree<T>::bfs(Node<T>* node) const {
    if (!node) return;

    std::queue<Node<T>*> q;
    q.push(node);

    while (!q.empty()) {
        Node<T>* current = q.front();
        q.pop();
        std::cout << current->data << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

template <typename T>
void BinaryTree<T>::bfs() const {
    bfs(root);
}

template <typename T>
void BinaryTree<T>::printDfs() const {
    dfs();
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::printBfs() const {
    bfs();
    std::cout << std::endl;
}