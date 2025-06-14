class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int minAbove = matrix[i - 1][j];
                if (j > 0) minAbove = min(minAbove, matrix[i - 1][j - 1]);
                if (j < n - 1) minAbove = min(minAbove, matrix[i - 1][j + 1]);
                matrix[i][j] += minAbove;
            }
        }

        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};
