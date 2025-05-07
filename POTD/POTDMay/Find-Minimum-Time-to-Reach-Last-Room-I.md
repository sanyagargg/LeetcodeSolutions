# Minimum Time to Reach the Bottom-Right Room in a Dungeon

## Problem Statement

You are given an `n x m` grid of rooms representing a dungeon. Each room `(i, j)` has an entry in a 2D array `moveTime[i][j]`, which denotes the earliest time (in seconds) at which you can **start** moving into that room. You begin at room `(0, 0)` at time `t = 0`. From any room, you can move to any adjacent room (up, down, left, right), and each move **always** takes exactly **1 second** once you begin.

**Goal:** Compute the minimum time required to reach room `(n - 1, m - 1)`.

**Constraints:**
- `2 <= n == moveTime.length <= 50`
- `2 <= m == moveTime[i].length <= 50`
- `0 <= moveTime[i][j] <= 10^9`

## Examples

**Example 1:**

```text
Input: moveTime = [[0, 4],
                   [4, 4]]
Output: 6
Explanation:
- At time 0, you are at (0,0).
- You must wait until t = 4 to enter either (0,1) or (1,0).
- Move to (1,0) at t = 4 → arrive at t = 5.
- At t = 5, move to (1,1) → arrive at t = 6.

**Example 2:**
```text
Input: moveTime = [[0, 0, 0],
                   [0, 0, 0]]
Output: 3
Explanation:
- No waiting is needed; just 3 moves down/right, each taking 1 second.

**Example 3:**
```text
Input: moveTime = [[0, 1],
                   [1, 2]]
Output: 3


## Approach

1. **Model as Shortest Path:**  
   Treat each cell `(i,j)` as a node. The “distance” to a node is the earliest time you can arrive there.

2. **State & Priority Queue (Dijkstra):**  
   - Maintain a 2D array `dist[i][j]` = minimum arrival time at `(i,j)`.  
   - Use a min-heap (priority queue) storing tuples `(time, i, j)`, ordered by `time`.

3. **Transition Rule:**  
   From `(i,j)` at time `t`, to move into neighbor `(ni,nj)`:
   - You must wait until `t >= moveTime[ni][nj]`.  
   - Once allowed, moving takes 1 second.  
   - Therefore, the candidate arrival is  
     ```text
     start_time = max(t, moveTime[ni][nj])
     arrival = start_time + 1
     ```

4. **Complexity:**  
   There are `O(nm)` nodes and up to `4nm` edges. Each heap operation costs `O(log(nm))`, giving `O(nm log(nm))`.

## Learnings

- Adapting Dijkstra’s algorithm to handle time‑dependent edge availability.  
- Using a priority queue to always explore the earliest possible state first.  
- Handling required waiting times by taking `max(current_time, allowed_time)`.  
- The pattern applies to any scenario where moves have fixed durations but variable earliest‑start constraints.
