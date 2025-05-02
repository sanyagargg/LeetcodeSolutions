# Implement `pow(x, n)` (Binary Exponentiation)

## Problem Statement

Implement a function `pow(x, n)` that calculates `x` raised to the power `n` (i.e., `x^n`).

### Example 1:

**Input:** `x = 2.00000`, `n = 10`  
**Output:** `1024.00000`

### Example 2:

**Input:** `x = 2.10000`, `n = 3`  
**Output:** `9.26100`

### Example 3:

**Input:** `x = 2.00000`, `n = -2`  
**Output:** `0.25000`  
**Explanation:** `2^-2 = 1 / (2^2) = 1 / 4 = 0.25`

---

## Approach 1: Brute Force (Not Used)

### Idea

We could calculate the power by repeatedly multiplying `x` by itself `n` times. For example, to calculate `x^n`, we would multiply `x` by itself `n` times.

### Time Complexity

- **O(n)**  
  (We perform `n` multiplications)

### Space Complexity

- **O(1)**  
  (We only need a constant amount of space to store the result)

### Why Not Used?

This approach is inefficient for large values of `n`, as it involves `n` multiplications. We need to find a more optimized approach.

---

## Approach 2: Optimized (Used in Code)

### Idea

Instead of performing `n` multiplications, we can use **binary exponentiation** (also known as exponentiation by squaring). The key observation is that:

- If `n` is even, then `x^n = (x^(n/2))^2`.
- If `n` is odd, then `x^n = x * (x^(n-1))`.

Using this approach, we can reduce the number of multiplications to `O(log n)` by halving `n` at each step.

### Steps:

1. **Handle Special Case for Negative Powers:**  
   If `n` is negative, we convert it to a positive exponent by calculating `1 / x^(-n)`.

2. **Binary Exponentiation:**  
   - If `n` is even, square the base and reduce `n` by half.
   - If `n` is odd, multiply the result by `x` and reduce `n` by one, making it even for the next step.

3. **Stop when `n` becomes 0**, at which point the result is the final value of `x^n`.

---

### Time Complexity

- **O(log n)**  
  Each step halves the value of `n`, leading to logarithmic complexity.

### Space Complexity

- **O(1)**  
  Only a constant amount of extra space is used for the result and variables.

---

## Learnings Through This Problem

- **Binary Exponentiation:**  
  This problem demonstrates the concept of binary exponentiation, which allows us to compute large powers efficiently in logarithmic time by breaking the problem into smaller subproblems.

- **Efficient Calculation:**  
  Instead of directly multiplying `x` `n` times, we take advantage of the binary representation of `n` to minimize the number of operations, reducing the time complexity from `O(n)` to `O(log n)`.

- **Handling Negative Exponents:**  
  The problem also emphasizes the need to handle cases where the exponent is negative by transforming the problem into a positive exponent scenario.

---
