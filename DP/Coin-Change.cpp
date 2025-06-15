class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = minimum coins needed to make sum i
        const int INF = amount + 1;      
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        // Build up from 1..amount
        for (int i = 1; i <= amount; ++i) {
            for (int c : coins) {
                if (c <= i) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
