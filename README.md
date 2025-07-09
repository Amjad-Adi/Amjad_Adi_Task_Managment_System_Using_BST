# Amjad_Adi_Task_Managment_System_Using_BST(10/10)
This is a console-based C program that helps users manage tasks efficiently using a Binary Search Tree (BST)
It supports multiple dynamic sorting modes based on task ID, name, date, or duration. Users can load tasks from a file, add/delete/search/perform tasks, restructure the BST, and analyze tree statistics — all through a menu-driven interface.

---

## ✅ Key Features

- 📥 **Load Tasks**: Read tasks from a structured file into a dynamically built BST.
- ➕ **Add Task**: Insert a new task with a unique ID, structured by the current sorting criteria.
- ❌ **Delete Task**: Remove a task by ID, name, date, or duration, based on the current tree structure.
- 🔍 **Search Task**: Search for a task by name, works in both sorted and unsorted structures.
- ✅ **Perform Task**: Mark any task as performed without removing it from the BST.
- 📂 **Restructure Tree**: Dynamically re-balance the BST based on any field: ID, name, date, or duration.
- 📊 **View Tree Stats**: Check the tree’s height, number of nodes, and number of leaves.
- 📈 **In-order Traversal**: View unperformed or performed tasks sorted by the current structure.

---

## 🧠 Data Structures

- `struct TaskNode`: Stores:
  - Task ID (int)
  - Task Name (string)
  - Task Date (string in `DD/MM/YYYY`)
  - Task Duration (double)
  - Performed Status (bool)
  - Left and Right Pointers
- `Tree`: The main BST that stores all task nodes.

---

## 🔄 BST Modes Supported

The tree can be dynamically sorted based on any of the following:

| Mode        | Meaning                 |
|-------------|--------------------------|
| ID          | Sorted by unique task ID |
| Name        | Sorted alphabetically    |
| Date        | Sorted by parsed date    |
| Duration    | Sorted numerically       |

---

## 🧪 Sample Operations

- **Insert Task**: Adds a task with unique ID into the correct position.
- **Delete Task**: Removes a task by key field (varies by tree mode).
- **Perform Task**: Marks a task as performed.
- **View Tasks**: Shows all tasks, filtered by performed/unperformed.
- **Restructure Tree**: Rebuilds tree based on a different field.
