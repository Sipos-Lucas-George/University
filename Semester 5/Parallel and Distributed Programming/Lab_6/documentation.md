# Hamiltonian Cycle Finder

This C++ program is designed to find Hamiltonian cycles in a graph. A Hamiltonian cycle is a cycle that visits each vertex exactly once and returns to the starting vertex.

## Overview

The program uses both single-threaded and multi-threaded approaches to find Hamiltonian cycles in a randomly generated graph. The graph is represented as an adjacency matrix, and the cycles are found using depth-first search.

## Code Structure

### Global Variables

- `VERTICES_COUNT`: Specifies the number of vertices in the graph.
- `STARTING_NODE`: Defines the starting vertex for the Hamiltonian cycle.
- `matrix`: Adjacency matrix representing the graph.
- `nodes`: Vector to store shuffled node indices.
- `result`: Vector to store the final Hamiltonian cycle.
- `path`: Vector to store the current path being explored.
- `x`: Atomic boolean flag to signal the discovery of a Hamiltonian cycle.
- `mtx`: Mutex for thread safety in accessing shared resources.

### Functions

1. **`generate_hamiltonian_cycle`**: Initializes the graph by shuffling node indices and creating edges. It introduces random edges to make the problem more challenging.

2. **`find_cycle`**: Performs a depth-first search to find Hamiltonian cycles in a single-threaded manner. The result is stored in the global variable `result`.

3. **`find_cycle_threaded`**: Similar to `find_cycle` but uses multiple threads to explore different paths concurrently. It creates threads when a certain depth of the search tree is reached.

4. **`time`**: Measures and prints the execution time of a given function.

### Main Function

- **`main`**: Generates a Hamiltonian cycle graph, initializes the atomic flag `x`, and measures the execution time for both single-threaded and multi-threaded Hamiltonian cycle finding functions.

## How to Run

1. Compile the program using a C++ compiler.
2. Execute the compiled binary.

## Output

The program outputs the execution time of the single-threaded and multi-threaded Hamiltonian cycle finding functions.

## Notes

- The `generate_hamiltonian_cycle` function creates a graph with a shuffled order of nodes and introduces random edges to make the problem more interesting.
- The `find_cycle_threaded` function utilizes multithreading to explore different paths concurrently, potentially improving performance.

## Conclusion

This program demonstrates the exploration of Hamiltonian cycles in a graph using both single-threaded and multi-threaded approaches. It serves as an example of parallelizing a depth-first search algorithm for improved efficiency in certain scenarios.
