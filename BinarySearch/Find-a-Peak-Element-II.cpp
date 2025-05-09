class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int midCol = left + (right - left) / 2;

            // Find the row with the max element in midCol
            int maxRow = 0;
            for (int i = 1; i < m; ++i) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            // Get left and right neighbors (handling boundaries)
            int leftNeighbor = (midCol - 1 >= 0) ? mat[maxRow][midCol - 1] : -1;
            int rightNeighbor = (midCol + 1 < n) ? mat[maxRow][midCol + 1] : -1;

            if (mat[maxRow][midCol] > leftNeighbor && mat[maxRow][midCol] > rightNeighbor) {
                return {maxRow, midCol}; // Peak found
            } else if (rightNeighbor > mat[maxRow][midCol]) {
                left = midCol + 1; // Move right
            } else {
                right = midCol - 1; // Move left
            }
        }

        return {-1, -1}; // Should not reach here
    }
};
