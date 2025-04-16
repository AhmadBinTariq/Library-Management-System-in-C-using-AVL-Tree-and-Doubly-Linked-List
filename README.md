# 📚 Library Management System in C++ using AVL Tree and Doubly Linked List

---

## 📝 Description

This is a console-based Library Management System implemented in C++. It utilizes a **sorted Doubly Linked List** for maintaining a sequence of book records and an **AVL Tree** for efficient searching of books by their ISSN number. Each book entry includes details like title, number of copies, and multiple authors.

---

## 🚀 Features

- 📖 Add new books to the library
- ✏️ Update existing book records by ISSN
- 🗑️ Delete a book using its ISSN
- 🔍 Fast book lookup via AVL Tree
- 📋 Display all books in sorted order (by ISSN)
- ✅ Clean memory management with destructors

---

## 🧱 Data Structures Used

- **AVL Tree**  
  For efficient O(log n) search, insert, and delete operations by ISSN.

- **Doubly Linked List**  
  Stores books in sorted order based on their ISSN.

---

## 🧩 Project Structure

| File Name              | Description                                      |
|------------------------|--------------------------------------------------|
| `main.cpp`             | Entry point of the program                       |
| `Book.h`               | Defines the `Book` class with all attributes     |
| `DLL_Node.h`           | Node structure for the Doubly Linked List        |
| `Double_Linked_List.h` | Implementation of a sorted Doubly Linked List    |
| `AVL.h`                | Template-based AVL Tree for efficient search     |
| `Lib_sys.h`            | `Library` class that integrates AVL & DLL logic  |

## 🛠️ How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/AhmadBinTariq/Library-Management-System-in-C-using-AVL-Tree-and-Doubly-Linked-List

> 📌 **Note:**  
> This project is designed to be console-based and focuses on implementing core data structures in C++ such as **AVL Trees** and **Doubly Linked Lists**.  
> It does **not** include a graphical user interface (GUI) and is meant for educational and demonstration purposes, particularly in **Data Structures** and **Object-Oriented Programming (OOP)**.

## Author

**Ahmad Bin Tariq**    
GitHub: https://github.com/AhmadBinTariq  
LinkedIn: https://www.linkedin.com/in/ahmad-bin-tariq-b97184325/  
Email: ahmadbintariq19@gmail.com


