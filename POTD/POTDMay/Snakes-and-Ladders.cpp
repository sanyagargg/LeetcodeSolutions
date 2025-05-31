class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q; // {cell number, steps}
        q.push({1, 0});
        visited[1] = true;
        
        while (!q.empty()) {
            auto [cell, steps] = q.front(); q.pop();
            for (int i = 1; i <= 6; ++i) {
                int next = cell + i;
                if (next > n * n) continue;
                auto [row, col] = getCoordinates(next, n);
                if (board[row][col] != -1)
                    next = board[row][col];
                if (next == n * n)
                    return steps + 1;
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, steps + 1});
                }
            }
        }
        return -1;
    }

    pair<int, int> getCoordinates(int cell, int n) {
        int r = (cell - 1) / n;
        int c = (cell - 1) % n;
        if (r % 2 == 1)
            c = n - 1 - c;
        return {n - 1 - r, c};
    }
};