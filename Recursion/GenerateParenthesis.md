# Generate Parentheses

## Problem Statement

Given `n` pairs of parentheses, write a function to generate all combinations of **well-formed** parentheses.

A **well-formed** parentheses string is one where:
1. Every opening bracket `(` has a corresponding closing bracket `)`.
2. The brackets are properly nested.

### Example 1:

**Input:** `n = 3`  
**Output:** `["((()))","(()())","(())()","()(())","()()()"]`

### Example 2:

**Input:** `n = 1`  
**Output:** `["()"]`

---

## Approach 1: Brute Force (Not Used)

### Idea

We can generate all possible combinations of parentheses strings of length `2 * n` and check if each combination is valid. 

To check if a string is valid:
- Iterate through the string and ensure that no closing parenthesis `)` appears before its corresponding opening parenthesis `(`.

### Time Complexity

- **O(2^(2n))**  
  (Generating all combinations of strings of length `2 * n` leads to an exponential number of combinations)

### Space Complexity

- **O(n)**  
  (To store each string as we generate it)

### Why Not Used?

This approach is inefficient because the number of combinations grows exponentially with `n`. For larger values of `n`, this would be computationally expensive and impractical.

---

## Approach 2: Optimized (Used in Code)

### Idea

Instead of generating all possible combinations of parentheses, we use a **backtracking** approach to construct only valid parentheses combinations. The idea is to:
- Keep track of the number of open and close parentheses used so far.
- Only add an opening parenthesis `(` if we have not yet used `n` open parentheses.
- Only add a closing parenthesis `)` if the number of closing parentheses used so far is less than the number of opening parentheses used.

The recursive function explores both adding `(` and `)` while ensuring the resulting parentheses string remains well-formed.

### Steps:

1. **Backtracking:**  
   - Start with an empty string.
   - Add an opening parenthesis if we haven't used `n` open parentheses yet.
   - Add a closing parenthesis if the number of closing parentheses used so far is less than the number of opening parentheses used.

2. **Base case:**  
   - Once the string reaches a length of `2 * n`, we add the string to the result.

3. **Recursive calls:**  
   - Recursively call the function to explore further possibilities.

---

### Time Complexity

- **O(4^n / √n)**  
  The number of valid well-formed parentheses combinations is given by the `n`-th Catalan number, which grows as `O(4^n / √n)`.

### Space Complexity

- **O(n)**  
  We use recursion and need space to store intermediate results during the backtracking process. Thus, the space complexity is proportional to `n`.

---

## Learnings Through This Problem

- **Backtracking:**  
  This problem is a classic example of using backtracking to generate valid solutions. It avoids generating invalid solutions by pruning the search space early.
  
- **Efficient Solution Generation:**  
  By generating only valid combinations of parentheses, we avoid unnecessary computations and improve efficiency compared to brute force.

- **Recursive Thought Process:**  
  The recursive approach helps break the problem into smaller subproblems where at each step, we make a decision to either add an opening or closing parenthesis while maintaining the constraints.

---
