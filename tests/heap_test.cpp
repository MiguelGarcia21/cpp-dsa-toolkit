#include <gtest/gtest.h>
#include "Heap.h"

TEST(HeapTest, InsertMaxHeap) {
    Heap<int> heap(HeapType::MAX);
    heap.insertItem(10);
    heap.insertItem(20);
    heap.insertItem(5);
    EXPECT_EQ(heap.top(), 20);
}

TEST(HeapTest, InsertMinHeap) {
    Heap<int> heap(HeapType::MIN);
    heap.insertItem(10);
    heap.insertItem(20);
    heap.insertItem(5);
    EXPECT_EQ(heap.top(), 5);
}

TEST(HeapTest, ExtractTopMaxHeap) {
    Heap<int> heap(HeapType::MAX);
    heap.insertItem(30);
    heap.insertItem(10);
    heap.insertItem(40);
    EXPECT_EQ(heap.extractTop(), 40);
    EXPECT_EQ(heap.top(), 30);
}

TEST(HeapTest, ExtractTopMinHeap) {
    Heap<int> heap(HeapType::MIN);
    heap.insertItem(30);
    heap.insertItem(10);
    heap.insertItem(40);
    EXPECT_EQ(heap.extractTop(), 10);
    EXPECT_EQ(heap.top(), 30);
}

TEST(HeapTest, DeleteExistingItem) {
    Heap<int> heap(HeapType::MAX);
    heap.insertItem(10);
    heap.insertItem(20);
    heap.insertItem(15);
    heap.deleteItem(20);
    EXPECT_NE(heap.top(), 20);
    EXPECT_EQ(heap.size(), 2);
}

TEST(HeapTest, DeleteNonexistentItem) {
    Heap<int> heap(HeapType::MAX);
    heap.insertItem(10);
    testing::internal::CaptureStderr();
    heap.deleteItem(999);  // Should not crash
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_NE(output.find("Value not found"), std::string::npos);
}

TEST(HeapTest, HeapifyWorks) {
    Heap<int> heap(HeapType::MIN);
    std::vector<int> data = { 8, 6, 7, 3, 2 };
    heap.heapify(data);
    EXPECT_EQ(heap.top(), 2);
    EXPECT_EQ(heap.size(), 5);
}

TEST(HeapTest, TopThrowsIfEmpty) {
    Heap<int> heap(HeapType::MAX);
    EXPECT_THROW(heap.top(), std::out_of_range);
}

TEST(HeapTest, ExtractThrowsIfEmpty) {
    Heap<int> heap(HeapType::MIN);
    EXPECT_THROW(heap.extractTop(), std::out_of_range);
}