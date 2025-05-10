#include <gtest/gtest.h>
#include "HashTable.h"

TEST(HashTableTest, InsertAndGet) {
    HashTable<int, std::string> ht;
    ht.insert(1, "one");
    ht.insert(2, "two");
    EXPECT_EQ(ht.get(1), "one");
    EXPECT_EQ(ht.get(2), "two");
}

TEST(HashTableTest, OverwriteValue) {
    HashTable<int, std::string> ht;
    ht.insert(1, "one");
    ht.insert(1, "uno");
    EXPECT_EQ(ht.get(1), "uno");
}

TEST(HashTableTest, RemoveKey) {
    HashTable<int, std::string> ht;
    ht.insert(1, "one");
    EXPECT_TRUE(ht.remove(1));
    EXPECT_FALSE(ht.contains(1));
}

TEST(HashTableTest, RemoveNonexistentKey) {
    HashTable<int, std::string> ht;
    EXPECT_FALSE(ht.remove(999));
}

TEST(HashTableTest, ContainsKey) {
    HashTable<int, std::string> ht;
    ht.insert(5, "five");
    EXPECT_TRUE(ht.contains(5));
    EXPECT_FALSE(ht.contains(6));
}

TEST(HashTableTest, ClearTable) {
    HashTable<int, std::string> ht;
    ht.insert(1, "a");
    ht.insert(2, "b");
    ht.clear();
    EXPECT_TRUE(ht.isEmpty());
}

TEST(HashTableTest, GetThrowsIfNotFound) {
    HashTable<int, std::string> ht;
    EXPECT_THROW(ht.get(123), std::out_of_range);
}