class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        
        // Initialize queue with rotten oranges and count fresh
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2) q.push({r, c});
                else if (grid[r][c] == 1) fresh++;
            }
        }
        
        if (fresh == 0) return 0;  // No fresh oranges initially
        
        int minutes = 0;
        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while (!q.empty()) {
            int size = q.size();
            bool rottenThisRound = false;
            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();
                for (auto& d : directions) {
                    int nr = r + d.first;
                    int nc = c + d.second;
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                        rottenThisRound = true;
                    }
                }
            }
            if (rottenThisRound) minutes++;
        }
        
        return fresh == 0 ? minutes : -1;
    }
};
