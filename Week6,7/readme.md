Problem-1 Multistage Graph
Given a directed weighted multistage graph with n vertices and e edges,
find the minimum cost path from source (vertex 0) to destination (vertex n-1).
Algorithm Used
Dynamic Programming (Backward Approach) - Horowitz & Sahani
Time and Space Complexity
ComplexityValueReasonTimeO(V + E)Each vertex and edge processed once in DPSpaceO(V)cost_dp[] and next[] arrays of size V
Input

V = number of vertices
E = number of edges
Each edge: from, to, cost

Output

Minimum cost from vertex 0 to vertex V-1
Optimal path taken

Problem-2 Cycledetection
Problem Statement — explains what a cycle is, what a DAG is, and what the program does in simple language.
Algorithm — DFS with 3-color marking (0=unvisited, 1=in stack, 2=done). Back edge to a Gray node = cycle found.
Complexities:
ValueReasonTimeO(V+E)DFS visits every vertex and edge onceSpaceO(V²)Adjacency matrix is V×VStackO(V)DFS recursion depth
Example — shows a sample graph, its matrix, and the expected output.
