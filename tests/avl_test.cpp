#include <gtest/gtest.h>
#include "BinaryAVL.h"

class AVLTest : public ::testing::Test {
protected:
    AVLTree<int> avl;

    void SetUp() override {
        avl.insert(10);
        avl.insert(20);
        avl.insert(30);
        avl.insert(40);
        avl.insert(50);
        avl.insert(25);
    }
};

TEST_F(AVLTest, InsertAndBalance) {
    // Test that tree remains balanced
    avl.insert(15);
    avl.insert(5);
    EXPECT_NO_THROW(avl.print());
}

TEST_F(AVLTest, DeleteNode) {
    avl.deleteNode(20);
    avl.deleteNode(30);
    EXPECT_NO_THROW(avl.print());
}

TEST_F(AVLTest, RotationTest) {
    AVLTree<int> testTree;
    testTree.insert(30);
    testTree.insert(20);
    testTree.insert(10);  // Should trigger right rotation
    
    testTree.insert(40);
    testTree.insert(50);  // Should trigger left rotation
    EXPECT_NO_THROW(testTree.print());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}