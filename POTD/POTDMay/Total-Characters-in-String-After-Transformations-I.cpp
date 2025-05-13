class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    // Helper to compute length after t transformations for character c
    int dfs(char c, int t) {
        if (t == 0) return 1;
        int idx = c - 'a';
        if (dp[idx][t] != -1) return dp[idx][t];

        if (c == 'z') {
            // 'z' → "ab", so calculate length of 'a' and 'b' after t-1 transformations
            dp[idx][t] = (dfs('a', t - 1) + dfs('b', t - 1)) % MOD;
        } else {
            // c → next character
            dp[idx][t] = dfs(c + 1, t - 1);
        }

        return dp[idx][t];
    }

    int lengthAfterTransformations(string s, int t) {
        dp.assign(26, vector<int>(t + 1, -1));
        long long total = 0;

        for (char c : s) {
            total = (total + dfs(c, t)) % MOD;
        }

        return total;
    }
};
