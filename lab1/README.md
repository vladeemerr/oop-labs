# Lab #1: Introduction to C++

## Goals
- Implementing classes in C++
- Managing memory in C++
- Studying fundamental OOP concepts
- Introduction to classes in C++
- Introduction to operator overloading in C++
- Introduction to `friend` functions
- Introduction to I/O via standard libraries

## Task
According to the task variant, three shape classes must be implemented in C++.
Classes are implemented as follows:
- Should be named according to the file name of `.h` and `.cpp`
- Should be inherited from `Figure` base class
- Should contain a constructor, that accepts vertex coordinates from standard input
- Should contain generic methods:
   - `size_t VertexesNumber()` returns number of vertices in a shape
   - `double Area()` returns an area of the shape
   - `void Print(std::ostream &os)` prints formatted string of vertex coordinates in a shape
