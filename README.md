# Templated C++ Data Structures Toolkit Library

This project is a modular and extensible **C++ template library** for classic data structures. Designed for performance and educational clarity, each data structure is implemented using generic programming principles with separate header (`.h`) and implementation (`.tpp`) files, and includes a dedicated Google Test suite.

## 📁 Project Structure

```
include/        // Header files for each data structure
src/            // Template implementations
tests/          // Google Test unit tests
bin/            // (suggested for compiled test binaries) 
.vscode/        // (local for VS Code configurations and testing)
```

## ✅ Supported Data Structures

| Data Structure         | Header File           | Implementation File     | Test File                   |
| ---------------------- | --------------------- | ----------------------- | --------------------------- |
| AVL Tree               | `BinaryAVL.h`         | `BinaryAVL.tpp`         | `avl_test.cpp`              |
| Binary Search Tree     | `BinaryTree.h`        | `BinaryTree.tpp`        | `binarytree_test.cpp`       |
| Heap (Min/Max)         | `Heap.h`              | `Heap.tpp`              | `heap_test.cpp`             |
| Singly Linked List     | `LinkedList.h`        | `LinkedList.tpp`        | `linkedlist_test.cpp`       |
| Doubly Linked List     | `DoublyLinkedList.h`  | `DoublyLinkedList.tpp`  | `doublylinkedlist_test.cpp` |
| Hash Table (open addr) | `HashTable.h`         | `HashTable.tpp`         | `hashtable_test.cpp`        |
| Hash Table (chained)   | `HashTable_Chained.h` | `HashTable_Chained.tpp` | `hashtablechain_test.cpp`   |
| General Node           | `Node.h`              | `Node.tpp`              | `node_test.cpp`             |

---

## 🧪 Google Test Coverage

Each test file includes a suite of unit tests. Below is a summary of tested functionalities:

### AVL Tree Tests

| Test Name          | Description                           |
| ------------------ | ------------------------------------- |
| `InsertAndBalance` | Tests self-balancing insertions       |
| `DeleteNode`       | Tests deletions and rebalancing       |
| `RotationTest`     | Tests triggering left/right rotations |

---

### Binary Search Tree Tests

| Test Name                      | Description                      |
| ------------------------------ | -------------------------------- |
| `InsertAndSearch`              | Validates insertion and search   |
| `DeleteLeafNode`               | Deletion of leaf node            |
| `DeleteNodeWithOneChild`       | Deletion when one child exists   |
| `DeleteNodeWithTwoChildren`    | Replaces with in-order successor |
| `DFSTraversal`, `BFSTraversal` | Verifies tree traversal orders   |

---

### Heap Tests

| Test Name       | Description                      |
| --------------- | -------------------------------- |
| `InsertMaxHeap` | Tests max-heap insertions        |
| `InsertMinHeap` | Tests min-heap insertions        |
| `ExtractTop*`   | Tests extracting the top element |
| `DeleteItem`    | Tests arbitrary deletion         |
| `HeapifyWorks`  | Builds heap from a vector        |

---

### Linked List Tests

| Test Name            | Description                  |
| -------------------- | ---------------------------- |
| `AddFront`, `AddEnd` | Insertion at front and end   |
| `AddAt`              | Insert at arbitrary position |
| `DeleteAt`           | Deletes at index             |
| `Find`               | Searches for value           |

---

### Doubly Linked List Tests

| Test Name      | Description                 |
| -------------- | --------------------------- |
| `Reverse`      | Reverses the list in-place  |
| `PrintMethods` | Verifies output correctness |
| `EdgeCases`    | Handles boundary conditions |

---

### Hash Table (Open Addressing) Tests

| Test Name        | Description                          |
| ---------------- | ------------------------------------ |
| `InsertAndGet`   | Tests key-value insertion and lookup |
| `OverwriteValue` | Replaces value of existing key       |
| `ClearTable`     | Empties hash table                   |

---

### Hash Table (Chained) Tests

| Test Name                  | Description                  |
| -------------------------- | ---------------------------- |
| `InsertAndSize`            | Adds multiple values per key |
| `RemoveValue`, `RemoveKey` | Tests deletion logic         |
| `PrintOutput`              | Checks console output format |

---

### Node Tests

| Test Name                       | Description                          |
| ------------------------------- | ------------------------------------ |
| `Constructors`, `TreeStructure` | Validates node connectivity          |
| `MoveSemantics`                 | Ensures move constructor correctness |

---

## ⏱ Time Complexity

Below are per-operation time complexities for each structure:

### AVL Tree

| Operation       | Time Complexity |
| --------------- | --------------- |
| Insert          | O(log n)        |
| Delete          | O(log n)        |
| Search          | O(log n)        |
| Print (Inorder) | O(n)            |

---

### Binary Search Tree (Unbalanced)

| Operation  | Time Complexity |
| ---------- | --------------- |
| Insert     | O(n) worst-case |
| Delete     | O(n) worst-case |
| Search     | O(n) worst-case |
| Traversals | O(n)            |

---

### Heap

| Operation | Time Complexity |
| --------- | --------------- |
| Insert    | O(log n)        |
| Delete    | O(log n)        |
| Top       | O(1)            |
| Heapify   | O(n)            |

---

### Singly & Doubly Linked List

| Operation        | Time Complexity |
| ---------------- | --------------- |
| Add Front/End    | O(1)            |
| Add At           | O(n)            |
| Delete At        | O(n)            |
| Find             | O(n)            |
| Reverse (Doubly) | O(n)            |

---

### Hash Table (Open Addressing)

| Operation | Average Case | Worst Case |
| --------- | ------------ | ---------- |
| Insert    | O(1)         | O(n)       |
| Delete    | O(1)         | O(n)       |
| Search    | O(1)         | O(n)       |

---

### Hash Table (Chained)

| Operation | Average Case | Worst Case |
| --------- | ------------ | ---------- |
| Insert    | O(1)         | O(n)       |
| Delete    | O(1)         | O(n)       |
| Search    | O(1)         | O(n)       |

---

## 🔧 Build & Run Tests

Make sure you have [GoogleTest](https://github.com/google/googletest) installed and the folder bin created.

```bash
g++ -std=c++20 -Iinclude -Isrc -I<gtest_path> tests/avl_test.cpp -o bin/avl_test
./bin/avl_test
```

You can adapt the command for each test file as needed.

---

## 👨‍💻 Author

This project is built by Miguel Angel Garcia, Software Engineering student, aiming to learn and showcase core data structure implementations with best practices in C++ template design and testing.

---
