# 📚 C++ DSA Toolkit

Welcome to the **C++ DSA Toolkit** — a personal repository dedicated to implementing and documenting fundamental data structures and algorithms in C++. This project serves as a learning tool and a reference for anyone interested in understanding and applying core computer science concepts using C++.

---

## 🧰 Features

* **Templated Implementations**: Generic data structures using C++ templates for type flexibility.
* **Clean and Readable Code**: Emphasis on writing clear, maintainable, and well-documented code.
* **Educational Focus**: Designed to aid in learning and understanding the inner workings of data structures.
* **Modular Design**: Each data structure is implemented in its own module for ease of use and testing.

---

## 📂 Project Structure

```
cpp-dsa-compendium/
├── include/
│   ├── linked_list.hpp
│   ├── stack.hpp
│   ├── queue.hpp
│   ├── priority_queue.hpp
│   ├── hash_table.hpp
│   └── binary_tree.hpp
├── src/
│   ├── main.cpp
│   └── tests/
│       ├── test_linked_list.cpp
│       ├── test_stack.cpp
│       └── ...
├── .gitignore
└── README.md
```

* `include/`: Contains header files for each data structure.
* `src/`: Contains source files and test cases.
* `.gitignore`: Specifies files and directories to be ignored by Git.
* `README.md`: This file.

---

## 📦 Implemented Data Structures

### 🔗 Linked Lists

* **Singly Linked List**: Basic operations like insertion, deletion, and traversal.
* **Doubly Linked List**: Supports bidirectional traversal with previous and next pointers.

### 📚 Stack

* Implemented using arrays and linked lists.
* Supports typical stack operations: push, pop, peek, and isEmpty.

### 📬 Queue

* Implemented using arrays and linked lists.
* Supports enqueue, dequeue, peek, and isEmpty operations.

### 🏗️ Priority Queue (Heap)

* **Max Heap** and **Min Heap** implementations.
* Supports insertion, deletion, and heapify operations.

### 🗃️ Hash Table

* **Open Addressing**: Uses linear probing for collision resolution.
* **Chaining Method**: Uses linked lists to handle collisions.

### 🌳 Binary Tree

* Supports insertion, deletion, and traversal methods (in-order, pre-order, post-order).
* Includes depth-first search (DFS) and breadth-first search (BFS) algorithms.

---

## 🚧 Work in Progress

This repository is under active development. Planned additions include:

* **Graph Algorithms**: Implementations of BFS, DFS, Dijkstra's algorithm, etc.
* **Advanced Data Structures**: AVL trees, Red-Black trees, Tries, etc.
* **Algorithm Implementations**: Sorting algorithms, search algorithms, etc.
* **Unit Testing**: Comprehensive test cases for each data structure.

---

## 🛠️ Getting Started

### Prerequisites

* A C++ compiler supporting C++11 or later.
* CMake (optional, for building the project).

### Compilation

To compile the project:

```bash
g++ -std=c++11 src/main.cpp -o dsa_compendium
```

Or, if using CMake:

```bash
mkdir build
cd build
cmake ..
make
```

### Running Tests

Test cases are located in the `src/tests/` directory. Compile and run them individually to verify the correctness of each data structure.

---

## 🧪 Sample Usage

Here's how you might use the singly linked list implementation:

```cpp
#include "linked_list.hpp"

int main() {
    LinkedList<int> list;
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtHead(5);
    list.printList(); // Output: 5 -> 10 -> 20
    return 0;
}
```

---

## 📄 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## 🙌 Contributing

Contributions are welcome! Feel free to open issues or submit pull requests to enhance the functionality or add new data structures.

---

## 📫 Contact

For any questions or suggestions, please open an issue on the repository or contact me directly.

---

Feel free to customize this `README.md` to better fit your project's specifics or to add more detailed information about each data structure and its implementation.
