# Minimum Time to Reach Destination in Grid with Alternating Move Costs

## Problem Statement

You are given a dungeon with \(n \times m\) rooms arranged as a grid. Each room \((i, j)\) has a "moveTime" constraint, represented by a 2D array `moveTime` of size \(n \times m\). The value `moveTime[i][j]` indicates the earliest time (in seconds) at which you are allowed to start moving *into* room \((i, j)\). You start at the top-left room \((0, 0)\) at time \(t = 0\).

Movement rules:
- You may move to any of the four adjacent rooms (up, down, left, right) if it lies within the grid boundaries.
- Moving between adjacent rooms takes 1 second for one move and 2 seconds for the next move, alternating between 1 and 2 seconds for each step.
- You can only start traversing into room \((i, j)\) at or after time `moveTime[i][j]`.

Return the minimum time required to reach the bottom-right room \((n-1, m-1)\).

### Constraints
- \(2 \le n = \text{moveTime.length} \le 750\)
- \(2 \le m = \text{moveTime[i].length} \le 750\)
- \(0 \le \text{moveTime}[i][j] \le 10^9\)

## Examples

**Example 1**:
Input: moveTime = [[0,4],
                  [4,4]]
Output: 7

Explanation:
- Wait until t=4, then move (0,0)->(1,0) in 1s (arrive at t=5).
- Next move costs 2s, but room (1,1) requires t>=4 to enter, so we start at t=5 and arrive at t=7.

**Example 2**;
Input: moveTime = [[0,0,0,0],
                  [0,0,0,0]]
Output: 6

Explanation:
Path: (0,0)→(1,0) in 1s (t=1), →(1,1) in 2s (t=3), →(1,2) in 1s (t=4), →(1,3) in 2s (t=6).

**Example 3**;
Input: moveTime = [[0,1],
                  [1,2]]
Output: 4

Explanation:
- You must wait before entering certain rooms to respect their moveTime constraints.


## Approaches

### 1. Naïve / Brute-force BFS (Bad)
- **Idea**: Treat each room as a node; perform a standard BFS from `(0,0)` while carrying two extra pieces of information: current time and parity of move cost (1 s or 2 s).
- **Drawbacks**:
  - BFS assumes uniform edge weights, but here costs alternate and you may need to wait.
  - State space blows up because you must revisit with different timestamps.
  - Exponential in worst-case due to repeated waits and revisits.

### 2. BFS with State Explosion (Better)
- **Idea**: Model each state as `(i, j, parity)`, where `parity = 0` means next move costs 1 s and `parity = 1` means next costs 2 s. Use a deque: push 1 s moves to front and 2 s moves to back, handling waits explicitly.
- **Drawbacks**:
  - Not a true 0–1 BFS (costs are 1 and 2).
  - Managing waits in a deque is complex and error-prone.
  - Still high overhead in the presence of large waits.

### 3. Dijkstra over Expanded State Space (Best)
- **Idea**: Build an implicit graph on states `(i, j, parity)` and run Dijkstra:
  1. Each state has up to 4 neighbors `(ni, nj, parity^1)`.
  2. Edge weight =  
     ``` 
     wait_time + (parity == 0 ? 1 : 2)
     ```
     where  
     ``` 
     wait_time = max(0, moveTime[ni][nj] - current_time)
     ```
  3. Use a min-heap (priority queue) over `(time, i, j, parity)` and a `dist[n][m][2]` table.

- **Time Complexity**:  
  \(O(n \, m \, \log(n \, m))\)  
- **Space Complexity**:  
  \(O(n \, m)\)

---

## Learnings

- **State Expansion**  
  When transition costs depend on the previous step (alternating 1 s/2 s), encode that “memory” in the state (parity bit).

- **Incorporating Waits**  
  If you can’t enter a room until a given time, add the necessary “wait time” to your edge-relaxation logic:
  ```cpp
  startTime = max(currentTime, moveTime[next_i][next_j]);
  arriveTime = startTime + stepCost;
---