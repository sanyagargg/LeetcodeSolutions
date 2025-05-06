# Build Array from Permutation

## Problem Statement

You are given a **zero-based permutation** `nums`, where:
- `nums` is an array of distinct integers from `0` to `nums.length - 1`.

Your task is to construct a new array `ans` such that:
ans[i] = nums[nums[i]]

for every valid `i`, and return the result.

---

## Examples

### Example 1:
**Input:**  
`nums = [0,2,1,5,3,4]`  
**Output:**  
`[0,1,2,4,5,3]`  
**Explanation:**  

ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
= [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
= [0,1,2,4,5,3]



### Example 2:
**Input:**  
`nums = [5,0,1,2,3,4]`  
**Output:**  
`[4,5,0,1,2,3]`

---

## Constraints

- `1 <= nums.length <= 1000`
- `0 <= nums[i] < nums.length`
- All values of `nums` are **unique**

---

## Approach 1: Direct Mapping (Using Extra Space)

### Idea

Since the permutation is guaranteed and values are within bounds, we can apply:
ans[i] = nums[nums[i]]


- Iterate through the array once.
- At each index, compute `ans[i] = nums[nums[i]]`.

### Time and Space Complexity

- **Time Complexity:** `O(n)`  
- **Space Complexity:** `O(n)` (for the result array)

---

## Approach 2: In-Place Encoding (Optimized)

### Idea

Use modular encoding to store both original and new values in the same array:
nums[i] = original_value + n * new_value

Then extract the new value by:
nums[i] = nums[i] / n


This works because all values are in the range `[0, n-1]`, so encoding won’t overflow if `n * n` fits in an integer.

### Steps

1. First pass:  
   Encode new value at each index using:
nums[i] = nums[i] + n * (nums[nums[i]] % n)


2. Second pass:  
Decode new value using:
nums[i] = nums[i] / n


### Time and Space Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)` (in-place)

---

## Learnings Through This Problem

- **Permutation Validity:**  
Helps guarantee safe indexed access like `nums[nums[i]]`.

- **Encoding Two Values:**  
With modular arithmetic, two pieces of information can be stored in one variable.

- **In-Place Optimization Patterns:**  
Useful for reducing auxiliary memory usage while keeping performance intact.

---

## When to Use Which

| Approach            | Space Optimized | Use When                  |
|---------------------|-----------------|---------------------------|
| Direct Mapping      | ❌ No            | Simplicity is preferred   |
| In-Place Encoding   | ✅ Yes           | Memory usage is critical  |

---

