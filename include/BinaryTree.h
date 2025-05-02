#pragma once
#include "common.h"

template <typename T>
class BinaryTree {
private:
    Node<T>* root;

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