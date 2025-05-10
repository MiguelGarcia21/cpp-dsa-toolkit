#include <gtest/gtest.h>
#include "HashTable_Chained.h"

class HashTable_ChainedTest : public ::testing::Test {
protected:
    HashTable_Chained<std::string, int> table;

    void SetUp() override {
        table.insert("one", 1);
        table.insert("two", 2);
        table.insert("two", 22);
        table.insert("three", 3);
    }
};

TEST_F(HashTable_ChainedTest, Initialization) {
    HashTable_Chained<std::string, int> emptyTable;
    EXPECT_TRUE(emptyTable.isEmpty());
    EXPECT_EQ(emptyTable.size(), 0);
}

TEST_F(HashTable_ChainedTest, InsertAndSize) {
    EXPECT_EQ(table.size(), 4);
    table.insert("four", 4);
    EXPECT_EQ(table.size(), 5);
}

TEST_F(HashTable_ChainedTest, GetValues) {
    auto values = table.get("two");
    ASSERT_EQ(values.size(), 2);
    EXPECT_EQ(values.front(), 2);
    EXPECT_EQ(values.back(), 22);
}

TEST_F(HashTable_ChainedTest, ContainsKey) {
    EXPECT_TRUE(table.contains("one"));
    EXPECT_FALSE(table.contains("nonexistent"));
}

TEST_F(HashTable_ChainedTest, RemoveValue) {
    EXPECT_TRUE(table.remove("two", 2));
    EXPECT_EQ(table.size(), 3);
    EXPECT_FALSE(table.remove("two", 999)); // Non-existent value
}

TEST_F(HashTable_ChainedTest, RemoveKey) {
    EXPECT_TRUE(table.removeKey("two"));
    EXPECT_EQ(table.size(), 2);
    EXPECT_FALSE(table.contains("two"));
}

TEST_F(HashTable_ChainedTest, Clear) {
    table.clear();
    EXPECT_TRUE(table.isEmpty());
    EXPECT_EQ(table.size(), 0);
}

TEST_F(HashTable_ChainedTest, EdgeCases) {
    HashTable_Chained<std::string, int> emptyTable;
    EXPECT_TRUE(emptyTable.get("nonexistent").empty());
    EXPECT_FALSE(emptyTable.remove("nonexistent", 1));
    EXPECT_FALSE(emptyTable.removeKey("nonexistent"));
}

TEST_F(HashTable_ChainedTest, PrintOutput) {
    testing::internal::CaptureStdout();
    table.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("one") != std::string::npos);
    EXPECT_TRUE(output.find("two") != std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}