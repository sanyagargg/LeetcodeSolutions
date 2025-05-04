# Number of Equivalent Domino Pairs

## Problem Statement

You are given a list of `dominoes`, where each `dominoes[i] = [a, b]` represents a domino tile with numbers `a` and `b`.

Two dominoes are considered **equivalent** if one domino can be rotated to equal the other. That is, `[a, b]` is equivalent to `[b, a]`.

Your task is to return the **number of pairs** `(i, j)` such that `0 <= i < j < dominoes.length` and `dominoes[i]` is equivalent to `dominoes[j]`.

---

## Examples

### Example 1:
**Input:**  
`dominoes = [[1,2],[2,1],[3,4],[5,6]]`  
**Output:** `1`  
**Explanation:**  
Only `[1,2]` and `[2,1]` form a matching pair.

---

### Example 2:
**Input:**  
`dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]`  
**Output:** `3`  
**Explanation:**  
Three pairs can be formed from the three `[1,2]` dominoes.

---

## Constraints

- `1 <= dominoes.length <= 4 * 10^4`
- `dominoes[i].length == 2`
- `1 <= dominoes[i][j] <= 9`

---

## Approach: Frequency Counting With Normalized Keys

### Idea

Dominoes like `[a, b]` and `[b, a]` should be treated as identical. To achieve this:
- Normalize each domino by storing the smaller value first: `key = min(a, b) * 10 + max(a, b)`.
- Use a hash map or array to count how many times each normalized key appears.
- For each new domino, the number of equivalent pairs it forms is equal to the number of previous dominoes with the same key.

---

### Steps

1. Initialize a hash map or array `count` to store frequencies of each normalized domino.
2. For each domino:
   - Normalize it with `min(a,b)*10 + max(a,b)`.
   - Add the current count of that key to the result.
   - Increment the count for that key.
3. Return the final result.

---

## Time and Space Complexity

- **Time Complexity:** `O(n)`  
  We process each domino once in constant time.

- **Space Complexity:** `O(1)`  
  Only 45–55 unique domino keys possible, so map size is constant.

---

## Learnings Through This Problem

- **Normalization Simplifies Equivalence:**  
  Transforming input into a canonical form reduces logic complexity.

- **Hashing for Counting Patterns:**  
  Using maps or arrays is a fast way to count and detect duplicates.

- **Avoiding Nested Loops for Pairs:**  
  By counting frequencies, we convert a potential O(n²) problem into O(n).

---
