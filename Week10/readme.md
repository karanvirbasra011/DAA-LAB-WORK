# Travelling Salesman Problem (TSP)

## Problem Statement
Given n cities and the distance between every pair of cities,
a salesman starts from city 0, must visit every city exactly
once, and return back to city 0.

Find the minimum cost route (tour) that covers all cities
and comes back to the starting city.

Example:
  4 cities with roads between them.
  Brute force checks all routes = (n-1)! = 6 routes.
  DP finds the same answer much faster.

## Algorithm Used
Dynamic Programming - Horowitz and Sahani Method

  Notation:
    g(i, S) = minimum cost to go from city i,
              visit all cities in set S exactly once,
              and return to city 0

  Recurrence:
    g(i, S) = min over all j in S of:
              d[i][j] + g(j, S - {j})

  Base Case:
    g(i, empty) = d[i][0]
    (no cities left, go directly back to city 0)

  Final Answer:
    g(0, {1, 2, 3, ..., n-1})
    Start from city 0, visit all other cities, return home.

  Set S is stored as a bitmask (binary number):
    1101 means cities 0, 2, 3 are visited, city 1 is not.

## Time and Space Complexity

| Complexity | Value       | Reason                                         |
|------------|-------------|------------------------------------------------|
| Time       | O(2^n * n²) | 2^n subsets x n cities x n choices per state   |
| Space      | O(2^n * n)  | DP table g[n][2^n] and path[n][2^n]            |

## Comparison with Brute Force

| Method      | Time       | n=10          | n=20                  |
|-------------|------------|---------------|-----------------------|
| Brute Force | O(n!)      | 362,880       | 2.4 x 10^18           |
| DP (H&S)    | O(2^n * n²)| 102,400       | 419,430,400           |

DP is much faster than brute force for larger inputs.

## Input
- n = number of cities
- n x n distance matrix
    - d[i][j] = cost to travel from city i to city j
    - 99999   = no direct road between cities i and j

## Output
- Minimum tour cost
- Optimal route from city 0 visiting all cities and returning to 0

## Example
Input:
  4 cities
  0  10 15 20
  10  0 35 25
  15 35  0 30
  20 25 30  0

Output:
  Minimum Tour Cost = 80
  Optimal Tour: 0 -> 1 -> 3 -> 2 -> 0
