#pragma once
#include "common.h"
#include "Node.h"  // Use the central Node definition

template <typename T>
class BinaryTree {
private:
    Node<T>* root;  // Use the central Node class

    void dfs(Node<T>* node) const;
    void bfs(Node<T>* node) const;

public:
    BinaryTree();
    ~BinaryTree();

    void insert(T data);
    void deleteNode(T data);
    void dfs() const;
    void bfs() const;
    void printDfs() const;
    void printBfs() const;
};

#include "../src/BinaryTree.tpp"  // Include the template implementation
