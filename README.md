# Smart Route Planner using Graph Algorithms

A complete C++17 console-based application that simulates a smart road network system using graph algorithms and data structures. The project allows users to manage cities and roads, perform graph traversals, compute shortest paths, analyze network statistics, and persist graph data using file handling.

---

## Features

- Add City
- Remove City
- Add Road
- Remove Road
- Display Complete Road Network
- Search City
- Find Shortest Path using Dijkstra’s Algorithm
- BFS Traversal
- DFS Traversal
- Display Network Statistics
  - Total Cities
  - Total Roads
  - Connected Components
- Save Graph to File
- Load Graph from File
- Menu-Driven Interface
- Input Validation and Error Handling

---

## Technologies Used

- C++17
- STL
- Object-Oriented Programming
- Graph Algorithms
- File Handling

---

## Data Structure Used

The graph is represented using an adjacency list:

```cpp
unordered_map<string, vector<pair<string, int>>>
