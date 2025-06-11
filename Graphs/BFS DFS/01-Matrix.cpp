class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        queue<pair<int,int>> q;
        
        // Initialize: push all 0 cells into the queue and set 1 cells to a large number
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (mat[r][c] == 0) {
                    q.push({r, c});
                } else {
                    mat[r][c] = INT_MAX;
                }
            }
        }
        
        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (auto& d : directions) {
                int nr = r + d.first;
                int nc = c + d.second;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    if (mat[nr][nc] > mat[r][c] + 1) {
                        mat[nr][nc] = mat[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        return mat;
    }
};
