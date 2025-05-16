# Maze Generator and Solver - Python Version

A maze generation and solving project in Python. This version uses **Breadth-First Search (BFS)** for pathfinding and **randomized Prim's algorithm** for maze generation, resulting in complex and fully connected mazes.

## Features
- **Maze Generation:** Uses a randomized version of Prim's algorithm to create unpredictable, fully connected mazes.
- **Pathfinding Algorithm:** Implements **Breadth-First Search (BFS)** to find the optimal path from the entrance to the exit.
- **Dynamic Path Marking:** Marks the correct path with a clear visual indicator (`C`) for easy interpretation.
- **Customizable Maze Size:** Allows users to specify maze dimensions for flexible testing.
- **Boundary and Connectivity Logic:** Efficiently manages boundaries to prevent out-of-bounds errors and ensure valid path connections.
- **Randomized Direction Shuffling:** Adds an element of unpredictability to the maze structure.
- **Interactive Input:** Prompts the user for maze dimensions, enhancing the interactive experience.
- **Recursive Path Creation:** Uses recursion to carve paths through the maze for a more organic structure.

## Technologies Used
- **Python:** Core programming language.
- **Algorithms:** BFS for pathfinding, randomized Prim's for maze generation.
- **Data Structures:** 2D lists for maze representation, queues for BFS.

## How to Run
1. Make sure you have **Python 3.8+** installed.
2. Clone the repository to your local machine.
3. Run the script using the command:
   ```bash
   python maze_generator_solver.py

## Sample Output
-Ingrese el ancho del laberinto: 15
-Ingrese el alto del laberinto: 15

Se encontró una solución para el laberinto.

Laberinto después de resolver:
# # # # # # # # # # # # # # #
# E   #       #       #     #
# # # # # # # # # #   # #   #
#       #   #     #   #   # #
# # #   #   # # # #   # # # #
#   #   #   #     #         #
#   #   # # # # # # # # # # #
#   #   #   #       #   #   #
#   #   #   # # #   #   # # #
#   #   #   #   #   #       #
#   #   # # #   # # # # #   #
#   #       #   #         # #
#   # # # # # # # # # # #   #
#     #           #         #
# # # # # # # # # # # # # # S

