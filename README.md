# Social Network Graph Assignment

## Question 6

Implement a small social network using an adjacency matrix and adjacency list, perform BFS and DFS from vertex A, search for a specified vertex, compare the two representations, and determine the suitable representation for a sparse social network.

## Given Connections

- A-B
- A-C
- B-D
- B-E
- C-F
- E-F

Vertices: A, B, C, D, E, F

## Implementations

The C program implements:
- Adjacency Matrix
- Adjacency List
- BFS using both representations
- DFS using both representations
- Vertex search
- Edge checking and operation counting

## Execution Results

### BFS
- Matrix: A B C D E F — 36 neighbor checks
- List: A B C D E F — 12 neighbor checks

### DFS
- Matrix: A B D E F C — 36 neighbor checks
- List: A B D E F C — 12 neighbor checks

### Vertex Search
Vertex E was found after 5 comparisons.

### Edge Checking
For edge E-F:
- Matrix: 1 operation
- List: 2 operations

## Complexity Analysis

| Operation | Adjacency Matrix | Adjacency List |
|---|---|---|
| Space | O(V²) | O(V + E) |
| BFS | O(V²) | O(V + E) |
| DFS | O(V²) | O(V + E) |
| Edge checking | O(1) | O(degree) |

For this graph, V = 6 and E = 6.

## Comparison

The adjacency matrix gives direct edge checking, but it stores a position for every possible pair of vertices. The adjacency list stores only the actual connections and requires less space for a sparse graph. The execution also showed fewer neighbor checks for BFS and DFS with the adjacency list.

## Conclusion

The adjacency list is more suitable overall for this sparse social network because it uses less storage and performs traversal by examining only actual neighboring connections. The adjacency matrix is useful when frequent direct edge checking is required.

## Files

- `social_network.c` — C source code
- `input.txt` — input data
- `output.txt` — execution output
- `Trace_Tables_Social_Network.pdf` — BFS, DFS, search and edge-check trace tables
- `Complexity_Analysis.pdf` — time and space complexity
- `Comparison_and_Conclusion.pdf` — comparison table and final conclusion
- `README.md` — assignment summary
