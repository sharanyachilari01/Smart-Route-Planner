# Smart Route Planner using Graph Algorithms

## Overview
Smart Route Planner is a comprehensive C++17 application designed to simulate a navigation system and analyze road networks. This project utilizes graph theory and essential algorithms to manage cities, calculate the shortest paths, and provide insights into network connectivity.

## Features
- **City Management:** Add, remove, and search for cities within the network.
- **Road Management:** Establish and remove roads with designated distances.
- **Network Display & Statistics:** Visualize the entire road network, total roads, total cities, and connected components.
- **Route Finding:** Uses Dijkstra's algorithm to compute the shortest path and distance between any two cities.
- **Graph Traversals:** Perform Breadth-First Search (BFS) and Depth-First Search (DFS) traversals to explore the network.
- **File Handling:** Save your network configurations to a text file and load them on demand.

## Project Structure
- `Graph.h` / `Graph.cpp` - Defines and manages the core graph structure using an adjacency list.
- `RouteFinder.h` / `RouteFinder.cpp` - Implements routing and traversal algorithms like Dijkstra, BFS, and DFS.
- `FileManager.h` / `FileManager.cpp` - Handles saving and loading the graph network to and from files.
- `main.cpp` - Provides a menu-driven command-line interface.
- `sample_data.txt` - Sample city and road configuration for testing.
- `Makefile` - Streamlined building script.

## Getting Started

### Prerequisites
- Make sure you have a C++17 compatible compiler (e.g., GCC `g++`).

### Building and Running
Navigate to the project directory and run the following commands:
```bash
make
./RoutePlanner
```
From the interactive menu, you can load the sample data by choosing option 12 and entering `sample_data.txt`.

## Resume Bullet Points
- Designed and implemented a smart routing system in C++17, simulating real-world navigation software to manage inter-city logistics and compute optimal paths.
- Engineered a robust, modular graph processing engine using STL structures (such as `unordered_map`, `priority_queue`, and `stack`), optimizing lookup times and network storage.
- Integrated Dijkstra’s algorithm to calculate shortest paths accurately alongside iterative BFS and DFS algorithms for exhaustive network traversals and connectivity analytics.
- Developed custom file I/O pipelines ensuring persistence of road network states, complete with a menu-driven UI to ensure seamless user interaction and data validity.
