class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> area; // id -> area size
        vector<vector<int>> idGrid(n, vector<int>(n, 0));
        int id = 2, maxArea = 0;

        // DFS to label each island with an id and calculate its area
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && idGrid[i][j] == 0) {
                    int a = dfs(grid, idGrid, i, j, id);
                    area[id] = a;
                    maxArea = max(maxArea, a);
                    ++id;
                }
            }
        }

        // Check each 0 and see what islands we can connect
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int total = 1; // we flip this 0 to 1
                    for (auto& [dx, dy] : directions) {
                        int ni = i + dx, nj = j + dy;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            int neighborId = idGrid[ni][nj];
                            if (neighborId && seen.count(neighborId) == 0) {
                                total += area[neighborId];
                                seen.insert(neighborId);
                            }
                        }
                    }
                    maxArea = max(maxArea, total);
                }
            }
        }

        return maxArea == 0 ? n * n : maxArea;
    }

private:
    vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& idGrid, int i, int j, int id) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 || idGrid[i][j] != 0)
            return 0;
        idGrid[i][j] = id;
        int area = 1;
        for (auto& [dx, dy] : directions) {
            area += dfs(grid, idGrid, i + dx, j + dy, id);
        }
        return area;
    }
};
