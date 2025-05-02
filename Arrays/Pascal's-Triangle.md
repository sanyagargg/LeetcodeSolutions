# Pascal's Triangle

## Problem Statement

Given an integer `numRows`, return the first `numRows` of **Pascal's Triangle**.

In Pascal's Triangle:
- The first and last elements of each row are `1`.
- Every other element is the sum of the two elements directly above it.

---

## Examples

### Example 1:
**Input:** `numRows = 5`  
**Output:**  
[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]


### Example 2:
**Input:** `numRows = 1`  
**Output:** `[[1]]`

---

## Constraints

- `1 <= numRows <= 30`

---

## Approach: Dynamic Programming (Top-Down Construction)

### Idea

We build Pascal's Triangle row by row:

1. The first and last elements in each row are always `1`.
2. For every other element at position `j`, we use the formula:  
   `triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]`

---

### Steps:

1. Create a 2D vector `triangle` with `numRows` rows.
2. Iterate through each row index `i` from `0` to `numRows - 1`.
3. Resize the current row to `i + 1` elements.
4. Set the first and last elements of each row to `1`.
5. For inner elements, compute each value as the sum of the two elements above it from the previous row.
6. Return the completed triangle.

---

## Time and Space Complexity

- **Time Complexity:** `O(numRows^2)`  
  Since each row has up to `i+1` elements, and we compute each element once.

- **Space Complexity:** `O(numRows^2)`  
  We use a 2D vector to store all the values.

---

## Learnings Through This Problem

- **Familiarity with Pascal’s Triangle Construction:**  
  It's a classic example of recursive relationships in arrays.

- **Index Management in 2D Structures:**  
  Useful practice in dynamically building nested vectors.

- **Efficient Memory Use in DP:**  
  This top-down approach efficiently constructs the triangle with minimal overhead.

---
