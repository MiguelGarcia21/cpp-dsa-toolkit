#pragma once
#include "common.h"

template <typename T>
class BinaryTree {
private:
    Node<T>* root;

    void dfs(Node<T>* node) const;
    void bfs(Node<T>* node) const;
    void clear(Node<T>* node);

public:
    BinaryTree();
    ~BinaryTree();

    void insert(T data);
    bool search(T data) const;
    void deleteNode(T data);
    void dfs() const;
    void bfs() const;
    void printDfs() const;
    void printBfs() const;
};

#include "../src/BinaryTree.tpp" 