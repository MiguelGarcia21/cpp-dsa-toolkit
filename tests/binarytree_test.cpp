#include <gtest/gtest.h>
#include "BinaryTree.h"

class BinaryTreeTest : public ::testing::Test {
protected:
    BinaryTree<int> tree;

    void SetUp() override {
        tree.insert(50);
        tree.insert(30);
        tree.insert(70);
        tree.insert(20);
        tree.insert(40);
        tree.insert(60);
        tree.insert(80);
    }
};

TEST_F(BinaryTreeTest, InsertAndSearch) {
    EXPECT_TRUE(tree.search(50));
    EXPECT_TRUE(tree.search(30));
    EXPECT_TRUE(tree.search(70));
    EXPECT_TRUE(tree.search(20));
    EXPECT_FALSE(tree.search(100));
}

TEST_F(BinaryTreeTest, DeleteLeafNode) {
    tree.deleteNode(20);
    EXPECT_FALSE(tree.search(20));
    EXPECT_TRUE(tree.search(30));
}

TEST_F(BinaryTreeTest, DeleteNodeWithOneChild) {
    tree.insert(35);  // Becomes left child of 40
    tree.deleteNode(40);
    EXPECT_FALSE(tree.search(40));
    EXPECT_TRUE(tree.search(35));
}

TEST_F(BinaryTreeTest, DeleteNodeWithTwoChildren) {
    tree.deleteNode(50);  // Root with two children
    EXPECT_FALSE(tree.search(50));
    EXPECT_TRUE(tree.search(60));  // Successor should replace
}

TEST_F(BinaryTreeTest, DFSTraversal) {
    testing::internal::CaptureStdout();
    tree.printDfs();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output.substr(0, 8), "50 30 20");  // Check start of DFS
}

TEST_F(BinaryTreeTest, BFSTraversal) {
    testing::internal::CaptureStdout();
    tree.printBfs();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output.substr(0, 8), "50 30 70");  // Check start of BFS
}

TEST_F(BinaryTreeTest, DestructorClearsMemory) {
    BinaryTree<int>* tempTree = new BinaryTree<int>();
    tempTree->insert(100);
    tempTree->insert(50);
    tempTree->insert(150);
    delete tempTree;  // Should not leak memory
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}