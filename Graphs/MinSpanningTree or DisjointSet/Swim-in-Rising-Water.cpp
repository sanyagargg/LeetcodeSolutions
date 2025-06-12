class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);  // {time, row, col}

        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!pq.empty()) {
            auto [t, r, c] = pq.top(); pq.pop();
            if (visited[r][c]) continue;
            visited[r][c] = true;
            if (r == n - 1 && c == n - 1) return t;

            for (auto& [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    pq.emplace(max(t, grid[nr][nc]), nr, nc);
                }
            }
        }

        return -1;  // should never reach here
    }
};
