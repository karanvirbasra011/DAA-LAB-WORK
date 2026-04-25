Problem-1 Matrix Chain Multiplication

## Problem Statement
Given a sequence of n matrices M1, M2, M3, ..., Mn where matrix Mi
has dimensions p[i-1] x p[i], find the most efficient way to multiply
these matrices together.

Matrix multiplication is associative, meaning the order of operations
can be changed using parentheses without changing the result. However,
different orderings require different numbers of scalar multiplications.

The goal is to find the optimal parenthesization that minimizes the
total number of scalar multiplications needed to compute the product
M1 x M2 x M3 x ... x Mn.

Example:
  M1 = 10x30, M2 = 30x5, M3 = 5x60
  Option 1: (M1 x M2) x M3 = 4500 + 18000 = 27500 multiplications
  Option 2: M1 x (M2 x M3) = 9000 + 27000 = 36000 multiplications
  Best = Option 1 with 27500 multiplications

## Algorithm Used
Dynamic Programming (Bottom-Up)

  m[i][j] = minimum cost to multiply matrices i through j
  s[i][j] = best split point k that gave minimum cost

  Recurrence:
  m[i][j] = min over all k from i to j-1 of:
             m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]

  Base case:
  m[i][i] = 0  (single matrix needs 0 multiplications)

## Time and Space Complexity

| Complexity | Value  | Reason                                         |
|------------|--------|------------------------------------------------|
| Time       | O(n³)  | 3 nested loops: chain length, i, split point k |
| Space      | O(n²)  | Two 2D arrays m[n][n] and s[n][n]              |

## Input
- n = number of matrices
- n+1 dimensions p[0], p[1], ..., p[n]
  where matrix Mi has size p[i-1] x p[i]

## Output
- Minimum number of scalar multiplications
- Optimal parenthesization of the matrix chain

## Example
Input:
  n = 6
  p = {300, 355, 155, 555, 100, 200, 250}

Output:
  Minimum Cost = 37255000
Optimal Parenthesization = ((M1(M2(M3M4)))(M5M6))

Problem-2
# Multistage Graph - Forward and Backward Propagation

## Problem Statement
Given a directed weighted multistage graph with n vertices and m edges,
find the minimum cost path from source (vertex 0) to destination (vertex n-1)
using two approaches:

1. Forward Propagation  - starts from source (vertex 0) and moves forward
                          to find shortest path to destination (vertex n-1)

2. Backward Propagation - starts from destination (vertex n-1) and moves
                          backward to find shortest path to source (vertex 0)

Both approaches must give the same minimum cost and same optimal path.
The graph is represented as an adjacency matrix where adj[i][j] = weight
of directed edge from i to j, and 0 means no edge.

## Algorithm Used
Dynamic Programming with relaxation (similar to Bellman-Ford one pass)

  Forward:
    dist[0] = 0, all others = INF
    For each vertex i, relax all outgoing edges i -> j:
      if dist[i] + adj[i][j] < dist[j] then update dist[j]

  Backward:
    dist[n-1] = 0, all others = INF
    For each vertex i (reverse order), relax all edges i -> j:
      if dist[j] + adj[i][j] < dist[i] then update dist[i]

  Path is traced back using parent[] array.

## Time and Space Complexity

| Complexity | Value  | Reason                                          |
|------------|--------|-------------------------------------------------|
| Time       | O(V²)  | Two nested loops over all vertices (V x V)      |
| Space      | O(V²)  | Adjacency matrix stored as V x V array          |
| Extra      | O(V)   | dist[], parent[], path[] arrays of size V       |

## Input
- n = number of vertices (0 to n-1)
- m = number of edges
- Each edge: u v w  (directed edge from u to v with weight w)

## Output
- Forward Distance  : minimum cost from vertex 0 to vertex n-1
- Forward Path      : actual path taken (source to destination)
- Backward Distance : minimum cost from vertex n-1 to vertex 0
- Backward Path     : actual path taken (destination to source)

## Example
Input:
  n = 5, m = 7
  Edges:
    0 1 2
    0 2 4
    1 3 3
    2 3 1
    1 4 6
    3 4 2
    2 4 5

Output:
  Forward Distance : 8
  Forward Path     : 0 2 3 4
  Backward Distance: 8
  Backward Path    : 0 2 3 4
