class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        string result = dominoes;
        int left = 0;

        // Add sentinels to simplify boundary conditions
        result = 'L' + result + 'R';
        n += 2;

        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && result[j] == '.') j++;

            char leftState = result[i];
            char rightState = result[j];

            if (leftState == rightState) {
                // Case 1: 'L...L' or 'R...R'
                for (int k = i + 1; k < j; ++k) {
                    result[k] = leftState;
                }
            } else if (leftState == 'R' && rightState == 'L') {
                // Case 2: 'R...L'
                int l = i + 1, r = j - 1;
                while (l < r) {
                    result[l++] = 'R';
                    result[r--] = 'L';
                }
            }
            // Case 3: 'L...R' → do nothing

            i = j;
        }

        // Remove the sentinels
        return result.substr(1, n - 2);
    }
};


//time : O(N)
//space: O(N)