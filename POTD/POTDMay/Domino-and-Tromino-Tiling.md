# Number of Tilings for a 2 x n Board

## Problem Statement

You are given a 2 x `n` board and tiles of two shapes:

- A domino: a 2 x 1 tile that can be placed vertically or horizontally.
- A tromino: an L-shaped tile covering three squares.

Return the number of ways to completely tile the board using these tiles. Since the answer may be very large, return it **modulo 10⁹ + 7**.

Two tilings are considered different if at least one 4-directionally adjacent pair of cells is covered differently.

---

## Examples

### Example 1:
**Input:**  
`n = 3`  
**Output:** `5`  
**Explanation:**  
There are 5 ways to completely tile a 2 x 3 board using dominoes and trominoes.

### Example 2:
**Input:**  
`n = 1`  
**Output:** `1`

---

## Constraints

- `1 <= n <= 1000`

---

## Approach: Dynamic Programming (DP)

### Idea

This problem follows a recurrence similar to a modified Fibonacci series. We define:

- `dp[i]`: Number of ways to tile a 2 x i board.
- We find that:
  dp[i] = 2 * dp[i - 1] + dp[i - 3]


- This relation accounts for:
- Placing a domino vertically or horizontally.
- Placing an L-shaped tromino in two different orientations.

### Base Cases

- `dp[0] = 1` (empty board)
- `dp[1] = 1` (one vertical domino)
- `dp[2] = 2` (two vertical dominoes or two horizontal)
- `dp[3] = 5` (5 distinct configurations using dominoes and trominoes)

---

## Time and Space Complexity

- **Time Complexity:** `O(n)`  
Iterates from 4 to `n`, computing each `dp[i]` in constant time.

- **Space Complexity:** `O(n)`  
Stores all intermediate `dp` values in a vector of size `n+1`.

> ✅ This can be optimized to `O(1)` space by storing only the last few values used in the recurrence.

---

## Learnings Through This Problem

- **Recurrence Formulas Are Powerful:**  
Recognizing and constructing the recurrence relation is key to solving complex tiling problems.

- **Efficient Modulo Handling:**  
Taking modulo at each step helps avoid overflow and ensures correctness.

- **Dynamic Programming Optimization:**  
Once recurrence is found, we can iteratively compute the result without redundant computation.

---
