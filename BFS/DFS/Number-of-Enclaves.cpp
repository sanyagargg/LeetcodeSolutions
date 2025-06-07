class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        
        // Remove land connected to boundaries by DFS
        for (int r = 0; r < rows; ++r) {
            dfs(grid, r, 0);
            dfs(grid, r, cols - 1);
        }
        for (int c = 0; c < cols; ++c) {
            dfs(grid, 0, c);
            dfs(grid, rows - 1, c);
        }
        
        int count = 0;
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (grid[r][c] == 1)
                    count++;
        
        return count;
    }
private:
    void dfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size(), cols = grid[0].size();
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) return;
        grid[r][c] = 0;  // sink the land
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }
};
