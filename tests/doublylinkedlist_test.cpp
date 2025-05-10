#include <gtest/gtest.h>
#include "DoublyLinkedList.h"

class DoublyLinkedListTest : public ::testing::Test {
protected:
    DoublyLinkedList<int> list;

    void SetUp() override {
        list.addEnd(10);
        list.addEnd(20);
        list.addEnd(30);
    }
};

TEST_F(DoublyLinkedListTest, Initialization) {
    DoublyLinkedList<int> emptyList;
    EXPECT_TRUE(emptyList.isEmpty());
    EXPECT_EQ(emptyList.length(), 0);
}

TEST_F(DoublyLinkedListTest, AddFront) {
    list.addFront(5);
    EXPECT_EQ(list.length(), 4);
    EXPECT_EQ(list.find(5), 0);
}

TEST_F(DoublyLinkedListTest, AddEnd) {
    list.addEnd(40);
    EXPECT_EQ(list.length(), 4);
    EXPECT_EQ(list.find(40), 3);
}

TEST_F(DoublyLinkedListTest, AddAt) {
    list.addAt(15, 1);
    EXPECT_EQ(list.length(), 4);
    EXPECT_EQ(list.find(15), 1);
    EXPECT_EQ(list.find(20), 2);
}

TEST_F(DoublyLinkedListTest, DeleteAt) {
    list.deleteAt(1);
    EXPECT_EQ(list.length(), 2);
    EXPECT_EQ(list.find(20), -1);
    EXPECT_EQ(list.find(30), 1);
}

TEST_F(DoublyLinkedListTest, Find) {
    EXPECT_EQ(list.find(10), 0);
    EXPECT_EQ(list.find(20), 1);
    EXPECT_EQ(list.find(30), 2);
    EXPECT_EQ(list.find(40), -1);
}

TEST_F(DoublyLinkedListTest, Reverse) {
    list.reverse();
    EXPECT_EQ(list.find(30), 0);
    EXPECT_EQ(list.find(20), 1);
    EXPECT_EQ(list.find(10), 2);
}

TEST_F(DoublyLinkedListTest, EdgeCases) {
    DoublyLinkedList<int> emptyList;
    EXPECT_THROW(emptyList.deleteAt(0), std::out_of_range);
    EXPECT_THROW(emptyList.addAt(1, 1), std::out_of_range);
    
    emptyList.addFront(1);
    EXPECT_EQ(emptyList.length(), 1);
    emptyList.deleteAt(0);
    EXPECT_TRUE(emptyList.isEmpty());
}

TEST_F(DoublyLinkedListTest, PrintMethods) {
    testing::internal::CaptureStdout();
    list.printForward();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("10 <-> 20 <-> 30") != std::string::npos);

    testing::internal::CaptureStdout();
    list.printBackward();
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("30 <-> 20 <-> 10") != std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}