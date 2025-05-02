# Push Dominoes

## Problem Statement

There are `n` dominoes in a line, each initially standing upright. Some dominoes are pushed to the left (`L`) or right (`R`) at the start. Each second:

- A domino falling to the left will push the adjacent domino on its left.
- A domino falling to the right will push the adjacent domino on its right.
- If a domino is pushed from both directions at the same time, it stays upright due to equal opposing forces.

You are given a string `dominoes` where:

- `dominoes[i] == 'L'` → pushed to the left
- `dominoes[i] == 'R'` → pushed to the right
- `dominoes[i] == '.'` → not pushed

Return a string representing the final state of all dominoes.

---

## Examples

### Example 1:
**Input:** `dominoes = "RR.L"`  
**Output:** `"RR.L"`  
**Explanation:** The two 'R's keep falling right, the 'L' remains unaffected.

### Example 2:
**Input:** `dominoes = ".L.R...LR..L.."`  
**Output:** `"LL.RR.LLRRLL.."`  
**Explanation:** Each domino is pushed according to the described behavior and stabilizes in the final configuration.

---

## Constraints

- `1 <= dominoes.length <= 10^5`
- `dominoes[i]` is either `'L'`, `'R'`, or `'.'`

---

## Approach: Two Pointers with Sentinels

### Idea

We scan the dominoes string with a sliding window approach, processing segments between forces (`L` or `R`). By introducing sentinels (`L` at the beginning and `R` at the end), we avoid dealing with edge boundaries explicitly.

#### Key Observations:

1. **Same forces on both sides:**  
   - `'R...R'` → fill with `'R'`s  
   - `'L...L'` → fill with `'L'`s

2. **Opposing forces:**  
   - `'R...L'` → fill symmetrically from both ends until the middle

3. **Non-opposing:**  
   - `'L...R'` → remains unchanged (balanced forces)

---

### Steps:

1. Add sentinel values: `'L' + dominoes + 'R'`
2. Use two pointers `i` and `j` to find segments between force points.
3. Based on the characters at `i` and `j`, fill in the in-between characters appropriately.
4. After processing, remove the sentinel characters.

---

## Time and Space Complexity

- **Time Complexity:** `O(n)`  
  Each character is visited a constant number of times.

- **Space Complexity:** `O(n)`  
  A new string is constructed, and space is used for result storage.

---

## Learnings Through This Problem

- **Efficient Simulation with Sentinels:**  
  Sentinels help eliminate boundary edge cases and simplify logic.

- **Two-Pointer Traversal:**  
  Identifying segments using two pointers makes the simulation linear and clean.

- **Understanding Physics-like Propagation:**  
  The balance of forces idea, along with real-time propagation of changes, reflects problems involving simulations or time-based spreading effects.

---
