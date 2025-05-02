# Max Tasks Assignment with Magical Pills

## Problem Statement

You have `n` tasks and `m` workers. Each task has a strength requirement stored in a 0-indexed integer array `tasks`, with the `i`-th task requiring `tasks[i]` strength to complete. The strength of each worker is stored in a 0-indexed integer array `workers`, with the `j`-th worker having `workers[j]` strength. Each worker can only be assigned to a single task and must have a strength greater than or equal to the task's strength requirement (i.e., `workers[j] >= tasks[i]`).

Additionally, you have magical pills that will increase a worker's strength by `strength`. You can decide which workers receive the magical pills, however, you may only give each worker at most one magical pill.

Given the 0-indexed integer arrays `tasks` and `workers` and the integers `pills` and `strength`, return the **maximum number of tasks** that can be completed.

---

## Approach 1: Brute Force (Not Used)

### Idea

- Generate all possible assignments of workers to tasks, considering both normal and magical-strengthened workers.
- For each assignment:
  - Check if workers can complete the tasks without exceeding the number of magical pills available.

### Time Complexity

- **O(m^n)**  
  (Trying all possible assignments of tasks to workers is computationally expensive, especially for large `m` and `n`)

### Space Complexity

- **O(n)**  
  (To store each assignment combination)

### Why Not Used?

This approach is inefficient due to the large number of possible combinations, especially when `n` and `m` are large. The brute-force approach is impractical for the given input size.

---

## Approach 2: Optimized (Used in Code)

### Idea

We use a **binary search** on the maximum number of tasks (`k`) that can be assigned. For each value of `k`, we check if it's possible to assign the `k` hardest tasks to the `k` strongest workers, using magical pills as needed.

1. **Sorting tasks and workers:**  
   Sort both `tasks` and `workers` in increasing order to prioritize the most difficult tasks and weakest workers first.

2. **Binary search:**  
   We binary search on the possible maximum number of tasks (`k`), checking for each value if it's possible to assign the `k` hardest tasks to the `k` strongest workers using the available pills.

3. **Deque usage:**  
   We use a **deque** to efficiently track the strongest workers for each possible `k`. This allows us to decide which workers should receive the magical pills in an optimal way.

### Steps:

- Sort both `tasks` and `workers`.
- Perform binary search to find the maximum `k` such that `k` tasks can be assigned.

---

### Time Complexity

- **O(n log n + m log m + log(min(n, m)) * k)**  
  Sorting the tasks and workers takes `O(n log n)` and `O(m log m)`. The binary search over `k` takes `O(log(min(n, m)))`, and the check for each `k` requires iterating through up to `k` workers, which is `O(k)`. Overall, the time complexity is dominated by these steps.

### Space Complexity

- **O(k)**  
  We use a deque to store the strongest `k` workers. Hence, the space complexity is `O(k)`.

---

## Learnings Through This Problem

- **Binary Search with Constraints:**  
  Binary search is a powerful tool to solve optimization problems where we need to maximize or minimize a value based on certain constraints (in this case, the maximum number of tasks).

- **Efficient Worker Assignment:**  
  Sorting and using a deque allows us to assign tasks in an efficient manner, ensuring that workers are optimally utilized based on their strength.

- **Greedy Assignment with Pills:**  
  The concept of using magical pills greedily on the weakest eligible workers is a good strategy to maximize the number of tasks that can be completed.

- **Understanding Time Complexity in Binary Search:**  
  The key to solving this problem efficiently lies in reducing the problem size using binary search while ensuring each step (assigning workers) is done optimally in linear time.

---
