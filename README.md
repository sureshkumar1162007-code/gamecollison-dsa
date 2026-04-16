# 🎮 Efficient Collision Detection using Spatial Hashing in C

## 📌 Overview

This project implements an **efficient collision detection system** for a real-time game environment using **spatial hashing**.
It reduces unnecessary comparisons by checking only nearby objects instead of all object pairs.

---

## 🚨 Problem Statement

In real-time games, multiple objects (players, enemies, projectiles) move simultaneously.
A naive collision detection approach checks every pair of objects (**O(n²)**), which is inefficient for large datasets.

---

## 🎯 Objective

* Reduce collision detection complexity
* Use **hashing** for fast spatial lookup
* Detect collisions accurately using distance calculation
* Improve performance for real-time systems

---

## 🧠 Approach

### 🔹 Spatial Hashing

* The 2D space is divided into **grid cells**
* Each object is mapped to a cell using a **hash function**

### 🔹 Hash Table (Separate Chaining)

* Each cell stores objects using a **linked list**
* Handles collisions efficiently

### 🔹 Neighbor Search

* For each object, only:

  * Same cell
  * Adjacent cells
    are checked

### 🔹 Collision Detection

* Uses **Euclidean distance formula**
  [
  distance \le radius_1 + radius_2
  ]

---

## ⚙️ Algorithm Steps

1. Initialize hash table
2. Input object positions
3. Convert position → grid cell
4. Insert object into hash table
5. For each object:

   * Check nearby cells
   * Compute distance
   * Detect collision

---

## 💻 Technologies Used

* C Programming
* Data Structures (Hashing, Linked List)

---

## ▶️ How to Run

```bash
gcc program.c -o collision
./collision
```

---

## 📥 Sample Input

```
Enter number of objects: 4
Enter x y for Object 1: 4 5
Enter x y for Object 2: 2 3
Enter x y for Object 3: 6 7
Enter x y for Object 4: 8 9
```

---

## 📤 Sample Output

```
--- Collision Results ---
Collision between Object 1 and Object 3
Collision between Object 1 and Object 2
Collision between Object 3 and Object 4
```

---

## ⚡ Time Complexity

| Operation           | Complexity |
| ------------------- | ---------- |
| Insertion           | O(1)       |
| Lookup              | O(1)       |
| Collision Detection | ~O(n)      |

---

## 🚀 Advantages

* Reduces complexity from **O(n²) → O(n)**
* Faster for real-time applications
* Scalable for large number of objects

---

## ⚠️ Limitations

* Duplicate collision outputs (can be optimized)
* Fixed grid size may affect accuracy

---

## 🔥 Future Improvements

* Remove duplicate collision checks
* Dynamic resizing of hash table
* Variable radius for objects
* 3D collision detection support

---

## 🧾 Conclusion

Spatial hashing significantly improves collision detection efficiency by limiting checks to nearby objects.
This makes it highly suitable for **real-time game development**.

---
