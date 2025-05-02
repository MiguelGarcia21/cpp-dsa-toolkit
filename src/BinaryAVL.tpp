#pragma once
#include "../include/BinaryAVL.h"

// Constructor
template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

// Destructor
template <typename T>
AVLTree<T>::~AVLTree() {
    // Add logic to delete all nodes
}

template <typename T>
int AVLTree<T>::height(Node<T>* node) const {
    if (!node) return 0;
    return 1 + std::max(height(node->left), height(node->right));
}

template <typename T>
int AVLTree<T>::balanceFactor(Node<T>* node) const {
    if (!node) return 0;
    return height(node->left) - height(node->right);
}

template <typename T>
Node<T>* AVLTree<T>::rotateLeft(Node<T>* x) {
    Node<T>* y = x->right;
    x->right = y->left;
    if (y->left) y->left->parent = x;
    y->left = x;
    x->parent = y;
    return y;
}

template <typename T>
Node<T>* AVLTree<T>::rotateRight(Node<T>* y) {
    Node<T>* x = y->left;
    y->left = x->right;
    if (x->right) x->right->parent = y;
    x->right = y;
    y->parent = x;
    return x;
}

template <typename T>
Node<T>* AVLTree<T>::insert(Node<T>* node, T data) {
    if (!node) return new Node<T>(data);

    if (data < node->data) {
        node->left = insert(node->left, data);
        node->left->parent = node;
    } else {
        node->right = insert(node->right, data);
        node->right->parent = node;
    }

    int balance = balanceFactor(node);

    if (balance > 1 && data < node->left->data) {
        return rotateRight(node);
    }

    if (balance < -1 && data > node->right->data) {
        return rotateLeft(node);
    }

    if (balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

template <typename T>
void AVLTree<T>::insert(T data) {
    root = insert(root, data);
}

template <typename T>
Node<T>* AVLTree<T>::deleteNode(Node<T>* node, T data) {
    if (!node) return node;

    if (data < node->data) {
        node->left = deleteNode(node->left, data);
    } else if (data > node->data) {
        node->right = deleteNode(node->right, data);
    } else {
        if (!node->left) {
            Node<T>* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            Node<T>* temp = node->left;
            delete node;
            return temp;
        }

        Node<T>* temp = node->right;
        while (temp && temp->left) temp = temp->left;

        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}

template <typename T>
void AVLTree<T>::deleteNode(T data) {
    root = deleteNode(root, data);
}

template <typename T>
void AVLTree<T>::inorder(Node<T>* node) const {
    if (node) {
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
}

template <typename T>
void AVLTree<T>::print() const {
    inorder(root);
}
