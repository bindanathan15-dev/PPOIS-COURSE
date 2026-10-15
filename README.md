# BSUIR - PPOIS Laboratory Work #1

## 👤 Author
* Name: Nathan Binda Malundama  
* Year: 2nd Year Student  
* Faculty: FITU
* Speciality: Artificial Intelligence 

## 📂 Project Overview
This repository contains the complete implementation for Laboratory Assignment #1 focused on Object-Oriented Programming (OOP) fundamentals in C++. The project strictly fulfills all core academic constraints, including total encapsulation, separation of console UI from logical implementation, and deep copy operations.

### Implemented Variants:
1. Variant 1.1 - 3D Vector Math Engine:
   * Full coordinate encapsulation (x, y, z).
   * Length/norm calculation using std::sqrt.
   * Advanced arithmetic operator overloading (+, -, *, /, +=, -=, *=, /=).
   * 3D Cross Product calculation and length comparison overrides (>, >=, <, <=).
   * Directional angle cosine computation.

2. Variant 1.4 & 1.4.1 - Unordered Cantor Set Theory Engine:
   * Fully recursive data structure (std::vector<Set>) supporting nested subsets like {a, b, {c, d}, {}}.
   * Automatic internal duplicate removal to satisfy Cantor set integrity.
   * Logical operations: Union (+), Intersection (*), and Difference (-).
   * Indexing operator override [] for membership verification.
   * Combinatorial Power Set generator (2^N subsets).
   * Recursive terminal string parser (Set::fromString).

## 🛠️ How to Run
1. Open the TestSeparation.sln solution file inside Visual Studio 2022.
2. Ensure configuration is set to Debug or Release under x64.
3. Press F5 to compile and run the interactive console menu.
