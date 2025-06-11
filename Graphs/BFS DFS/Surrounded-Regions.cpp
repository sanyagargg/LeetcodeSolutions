class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int rows = board.size(), cols = board[0].size();

        // Mark 'O's on the border and connected to border as safe ('#')
        for (int r = 0; r < rows; ++r) {
            dfs(board, r, 0);
            dfs(board, r, cols - 1);
        }
        for (int c = 0; c < cols; ++c) {
            dfs(board, 0, c);
            dfs(board, rows - 1, c);
        }

        // Flip all 'O' to 'X' and '#' back to 'O'
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                else if (board[r][c] == '#') board[r][c] = 'O';
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, int r, int c) {
        int rows = board.size(), cols = board[0].size();
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O') return;
        board[r][c] = '#'; // mark as safe
        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
        dfs(board, r, c-1);
    }
};
