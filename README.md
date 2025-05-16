# Maze Generator and Solver in C++

This project is a maze generator and solver implemented in C++. It creates random mazes using depth-first search (DFS) for maze generation and breadth-first search (BFS) for pathfinding. The maze is represented as a 2D grid with walls, paths, an entry point, and an exit.

## Features
- **Maze Generation:** Uses a depth-first search algorithm to generate complex, interconnected mazes.
- **Pathfinding:** Solves the maze using breadth-first search, ensuring the shortest path is found.
- **Customizable Maze Size:** Allows the user to define the maze dimensions.
- **Random Path Generation:** Generates unpredictable, unique maze layouts every time.
- **Clear Path Display:** Marks the correct path from the entry to the exit once solved.
- **Boundary Handling:** Ensures proper wall creation and maze boundaries.

## Technologies Used
- **C++:** Core programming language.
- **Algorithms:** Depth-first search (DFS) for maze creation, breadth-first search (BFS) for pathfinding.
- **Randomization:** Uses the Mersenne Twister engine for high-quality random numbers.
- **Data Structures:** Vectors and queues for efficient pathfinding and maze generation.

## How to Run
1. Make sure you have a C++ compiler installed (e.g., g++ or MSVC).
2. Clone the repository to your local machine.
3. Compile the program:
   ```bash
   g++ -o laberinto.cpp

