class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
        return true;
    }

    bool isValid(const vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i)
            if (board[i][col] == c || board[row][i] == c)
                return false;
        int startRow = 3 * (row / 3), startCol = 3 * (col / 3);
        for (int i = startRow; i < startRow + 3; ++i)
            for (int j = startCol; j < startCol + 3; ++j)
                if (board[i][j] == c)
                    return false;
        return true;
    }
};
