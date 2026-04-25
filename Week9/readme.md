Floyd-Warshall Algorithm - All Pairs Shortest Path
Problem Statement
Given a directed weighted graph with n vertices represented as an
adjacency matrix, find the shortest path between every pair of
vertices (i, j) in the graph.
Unlike Dijkstra which finds shortest path from one source,
Floyd-Warshall solves the All Pairs Shortest Path (APSP) problem
meaning it finds shortest distances between ALL possible pairs
of vertices in a single run.
The graph is given as an adjacency matrix D where:
D[i][j] = weight of direct edge from i to j
D[i][j] = 9999 (INF) if no direct edge exists
D[i][i] = 0 (distance from a vertex to itself)
The algorithm works on graphs with positive or negative edge weights
but must NOT have negative weight cycles.
Algorithm Used
Dynamic Programming - Intermediate Vertex Relaxation
Key Idea:
For every pair (i, j), check if going through an
intermediate vertex k gives a shorter path than the
current known shortest path.
Recurrence:
D[i][j] = min( D[i][j],  D[i][k] + D[k][j] )
This is repeated for every k from 0 to n-1.
After k-th iteration, D[i][j] holds shortest path from
i to j using only vertices {0, 1, 2, ..., k} as intermediates.
Time and Space Complexity
ComplexityValueReasonTimeO(V³)Three nested loops: k, i, j each run V timesSpaceO(V²)Single 2D matrix D[V][V] updated in place
Input

n = number of vertices
n x n adjacency matrix

actual weight  = direct edge weight
9999           = no edge (treated as INF)



Output

D0 matrix : original input weight matrix
Final matrix : shortest distances between all pairs of vertices

Example
Input (4 vertices):
0     5   9999   10
9999  0    3    9999
9999 9999  0     1
9999 9999 9999   0
Output (after Floyd-Warshall):
0   5   8   9
INF 0   3   4
INF INF 0   1
INF INF INF 0
