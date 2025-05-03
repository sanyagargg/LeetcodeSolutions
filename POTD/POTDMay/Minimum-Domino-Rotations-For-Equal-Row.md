# Minimum Domino Rotations For Equal Row

## Problem Statement

In a row of dominoes, `tops[i]` and `bottoms[i]` represent the top and bottom halves of the *i-th* domino (each domino has two numbers from 1 to 6 — one on each half).

You are allowed to rotate the i-th domino, swapping `tops[i]` with `bottoms[i]`.

Your task is to return the **minimum number of rotations** required so that **all values in `tops` are the same** or **all values in `bottoms` are the same**.

If it is not possible, return `-1`.

---

## Examples

### Example 1:
**Input:**  
`tops = [2,1,2,4,2,2]`  
`bottoms = [5,2,6,2,3,2]`  
**Output:** `2`  
**Explanation:**  
By rotating the 2nd and 4th dominoes, all top values become 2.

---

### Example 2:
**Input:**  
`tops = [3,5,1,2,3]`  
`bottoms = [3,6,3,3,4]`  
**Output:** `-1`  
**Explanation:**  
It is not possible to make all values in either row the same.

---

## Constraints

- `2 <= tops.length <= 2 * 10^4`
- `bottoms.length == tops.length`
- `1 <= tops[i], bottoms[i] <= 6`

---

## Approach: Greedy Checking With Candidates

### Idea

We only need to check **two possible candidates** for the final uniform value:
- `tops[0]`
- `bottoms[0]`

For each candidate `target`:
- For every domino, check if it's possible to rotate it such that either top or bottom becomes `target`.
- Count the number of rotations needed to make all top values `target`, and separately all bottom values `target`.
- Return the minimum of the two.

---

### Steps

1. Try `target = tops[0]`:
    - If it works, return the minimum number of rotations.
2. Else, try `target = bottoms[0]`:
    - If it works, return the minimum rotations.
3. If neither works, return `-1`.

---

## Time and Space Complexity

- **Time Complexity:** `O(n)`  
  Each element is checked once for both candidates.

- **Space Complexity:** `O(1)`  
  Only a few integer variables are used.

---

## Learnings Through This Problem

- **Greedy Choice Based on Initial Candidates:**  
  By limiting checks to only two values, we reduce complexity.

- **Simultaneous Top & Bottom Tracking:**  
  Smart counting for both top and bottom rotations makes the solution efficient.

- **Avoiding Unnecessary Rotations:**  
  We ensure we only count when a rotation is truly needed and possible.

---
