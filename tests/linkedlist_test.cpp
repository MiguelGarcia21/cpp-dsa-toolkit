#include <gtest/gtest.h>
#include "../include/LinkedList.h"

TEST(LinkedListTest, AddFrontAndFind) {
    LinkedList<int> list;
    list.addFront(10);
    list.addFront(20);
    list.addFront(30);
    EXPECT_EQ(list.find(10), 2);
    EXPECT_EQ(list.find(30), 0);
}

TEST(LinkedListTest, AddEndAndFind) {
    LinkedList<int> list;
    list.addEnd(5);
    list.addEnd(15);
    EXPECT_EQ(list.find(5), 0);
    EXPECT_EQ(list.find(15), 1);
}

TEST(LinkedListTest, AddAtValidPosition) {
    LinkedList<int> list;
    list.addEnd(1);
    list.addEnd(3);
    list.addAt(2, 1);  // insert 2 between 1 and 3
    EXPECT_EQ(list.find(2), 1);
    EXPECT_EQ(list.length(), 3);
}

TEST(LinkedListTest, AddAtInvalidPositionThrows) {
    LinkedList<int> list;
    EXPECT_THROW(list.addAt(1, -1), std::out_of_range);
    EXPECT_THROW(list.addAt(1, 2), std::out_of_range);
}

TEST(LinkedListTest, DeleteAtPosition) {
    LinkedList<int> list;
    list.addEnd(10);
    list.addEnd(20);
    list.addEnd(30);
    list.deleteAt(1);
    EXPECT_EQ(list.find(20), -1);
    EXPECT_EQ(list.find(30), 1);
}

TEST(LinkedListTest, DeleteAtInvalidPositionThrows) {
    LinkedList<int> list;
    list.addEnd(1);
    EXPECT_THROW(list.deleteAt(5), std::out_of_range);
    EXPECT_THROW(list.deleteAt(-1), std::out_of_range);
}

TEST(LinkedListTest, FindElement) {
    LinkedList<std::string> list;
    list.addEnd("alpha");
    list.addEnd("beta");
    list.addEnd("gamma");
    EXPECT_EQ(list.find("beta"), 1);
    EXPECT_EQ(list.find("delta"), -1);
}
