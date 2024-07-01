# Pagerank-Algorithm
This C++ project implements the PageRank algorithm, crucial in search engine optimization and network analysis. It assigns scores to nodes based on their connections, determining their importance within the graph structure through iterative calculations until convergence.

## Features

- **Graph Representation**: Utilizes an unordered map to represent a graph where nodes are mapped to their outgoing links.
- **Initialization**: Initializes PageRank scores with a damping factor and sets up initial conditions for iterative computation.
- **Iterative Computation**: Computes PageRank iteratively using the damping factor and considering the graph structure.
- **Output**: Prints PageRank scores for nodes that have been visited and calculates the sum of PageRank scores.

## Project Structure

- **Main File**: `pagerank.cpp` contains the main program that reads input, initializes the graph, computes PageRank, and outputs results.
- **Functions**: Modular functions for building the graph (`build_graph`), initializing PageRank (`init_pagerank`), computing PageRank (`calculate_pagerank`), and printing results (`print_results`).

## How to Use

- **Compile**: Compile the `pagerank.cpp` file using a C++ compiler.
   ```bash
   g++ pagerank.cpp -o pagerank
- Run: Execute the compiled program with input redirection or by providing input directly.
bash

./pagerank < input.txt

## Example Input

1 2

2 3

3 1

## Example Output

1 = 0.191532

2 = 0.406004

3 = 0.402464

s = 1




