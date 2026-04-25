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

  Problem-2

  

Output:
  Minimum Cost = 37255000
  Optimal Parenthesization = ((M1(M2(M3M4)))(M5M6))
