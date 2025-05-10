#include <gtest/gtest.h>
#include "../include/Node.h"
#include <memory>
#include <string>

class NodeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }

    void TearDown() override {
        // Cleanup code if needed
    }
};

TEST_F(NodeTest, DefaultConstructor) {
    Node<int> node(42);
    
    EXPECT_EQ(node.data, 42);
    EXPECT_EQ(node.next, nullptr);
    EXPECT_EQ(node.prev, nullptr);
    EXPECT_EQ(node.left, nullptr);
    EXPECT_EQ(node.right, nullptr);
    EXPECT_EQ(node.parent, nullptr);
}

TEST_F(NodeTest, ParameterizedConstructor) {
    Node<int> left(10);
    Node<int> right(20);
    Node<int> parent(30);
    
    Node<int> node(15, &left, &right, &parent);
    
    EXPECT_EQ(node.data, 15);
    EXPECT_EQ(node.next, nullptr);
    EXPECT_EQ(node.prev, nullptr);
    EXPECT_EQ(node.left, &left);
    EXPECT_EQ(node.right, &right);
    EXPECT_EQ(node.parent, &parent);
}

TEST_F(NodeTest, PartialParameterizedConstructor) {
    Node<int> left(10);
    
    Node<int> node(15, &left);
    
    EXPECT_EQ(node.data, 15);
    EXPECT_EQ(node.next, nullptr);
    EXPECT_EQ(node.prev, nullptr);
    EXPECT_EQ(node.left, &left);
    EXPECT_EQ(node.right, nullptr);
    EXPECT_EQ(node.parent, nullptr);
}

TEST_F(NodeTest, PointerData) {
    auto value = std::make_unique<int>(100);
    Node<int*> node(value.get());
    
    EXPECT_EQ(node.data, value.get());
    EXPECT_EQ(*node.data, 100);
    EXPECT_EQ(node.next, nullptr);
    EXPECT_EQ(node.prev, nullptr);
    EXPECT_EQ(node.left, nullptr);
    EXPECT_EQ(node.right, nullptr);
    EXPECT_EQ(node.parent, nullptr);
}

TEST_F(NodeTest, ExplicitConstructorCheck) {
    // Test that implicit conversion is prevented
    auto createNode = [](const Node<int>&) {};
    
    // This should fail to compile if uncommented (which is what we want)
    // createNode(42);  // Should fail because constructor is explicit
    
    createNode(Node<int>(42));  // Should compile
}

TEST_F(NodeTest, BidirectionalRelationships) {
    Node<int> left(10);
    Node<int> right(20);
    
    Node<int> node(15, &left, &right);
    
    EXPECT_EQ(node.left, &left);
    EXPECT_EQ(node.right, &right);
    EXPECT_EQ(left.parent, &node);
    EXPECT_EQ(right.parent, &node);
}

TEST_F(NodeTest, TreeStructure) {
    Node<int> left_left(5);
    Node<int> left_right(7);
    Node<int> left(10, &left_left, &left_right);
    
    Node<int> right(20);
    
    Node<int> root(15, &left, &right);
    
    // Test left subtree
    EXPECT_EQ(root.left, &left);
    EXPECT_EQ(left.parent, &root);
    EXPECT_EQ(left.left, &left_left);
    EXPECT_EQ(left_left.parent, &left);
    EXPECT_EQ(left.right, &left_right);
    EXPECT_EQ(left_right.parent, &left);
    
    // Test right subtree
    EXPECT_EQ(root.right, &right);
    EXPECT_EQ(right.parent, &root);
    
    // Test data values
    EXPECT_EQ(root.data, 15);
    EXPECT_EQ(left.data, 10);
    EXPECT_EQ(right.data, 20);
    EXPECT_EQ(left_left.data, 5);
    EXPECT_EQ(left_right.data, 7);
}

TEST_F(NodeTest, MoveSemantics) {
    Node<int> original(42);
    Node<int> moved(std::move(original));
    
    EXPECT_EQ(moved.data, 42);
    EXPECT_EQ(moved.next, nullptr);
    EXPECT_EQ(moved.prev, nullptr);
    EXPECT_EQ(moved.left, nullptr);
    EXPECT_EQ(moved.right, nullptr);
    EXPECT_EQ(moved.parent, nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}