# Count Good Numbers

## Problem Statement

A **digit string** is called *good* if:

- Every digit at an **even index** (0-based) is an **even digit**: {0, 2, 4, 6, 8}  
- Every digit at an **odd index** is a **prime digit**: {2, 3, 5, 7}

Given an integer `n`, return the **total number of good digit strings of length `n`**.  
Since the result may be large, return it modulo `10^9 + 7`.

---

## Approach 1: Brute Force (Not Used)

### Idea

- Generate all possible digit strings of length `n` (total of `10^n` strings).  
- For each string:
  - Check if digits at even indices are even.
  - Check if digits at odd indices are prime.

### Time Complexity

- **O(10^n × n)**  
  (Generating and validating each string is very expensive)

### Space Complexity

- **O(n)**  
  (To store each generated string)

### Why Not Used?

This approach is **not feasible** for large values of `n` (up to `10^15`) because the number of combinations becomes too large.

---

## Approach 2: Optimized (Used in Code)

### Idea

Instead of generating strings, we calculate the **number of valid choices** for each index:

- **Even indices (0-based):** 5 valid digits → {0, 2, 4, 6, 8}  
- **Odd indices:** 4 valid digits → {2, 3, 5, 7}

Let:
- `even_count = (n + 1) / 2`  
- `odd_count = n / 2`

Then:
Total Good Strings = (5^even_count) * (4^odd_count) % MOD


To handle large powers efficiently, we use **fast modular exponentiation** (also known as binary exponentiation).

---

### Fast Modular Exponentiation

To compute `(base^exp) % mod` efficiently, we use the following idea:

- If `exp` is even, use: `(base^exp) = (base^(exp/2))^2`
- If `exp` is odd, use: `result = result * base % mod`

This reduces time complexity from O(n) to **O(log n)**.

---

### Time Complexity

- **O(log n)**  
  (Two fast exponentiations: one for base 5 and one for base 4)

### Space Complexity

- **O(1)**  
  (No extra memory beyond a few variables)

---

## Learnings Through This Problem

- **Pattern recognition:** Understand constraints for different positions instead of brute-forcing all possibilities.
- **Mathematical modeling:** Turning positional constraints into a product of choices is a powerful optimization.
- **Fast exponentiation:** A key technique to handle large powers under modulo efficiently.
- **Scalability mindset:** Always think about how an algorithm behaves as input size grows — especially when `n` is large.

---
