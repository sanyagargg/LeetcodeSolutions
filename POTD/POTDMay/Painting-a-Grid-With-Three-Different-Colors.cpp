class Solution {
public:
    int colorTheGrid(int m, int n) {
        const int MOD = 1e9 + 7;
        std::vector<int> valid_masks;
        std::unordered_map<int, std::vector<int>> transitions;

        // Generate all valid masks for a single column
        generateValidMasks(m, 0, 0, valid_masks);

        // Precompute transitions between masks
        for (int mask1 : valid_masks) {
            for (int mask2 : valid_masks) {
                if (isValidTransition(mask1, mask2, m)) {
                    transitions[mask1].push_back(mask2);
                }
            }
        }

        // Initialize DP
        std::unordered_map<int, int> dp;
        for (int mask : valid_masks) {
            dp[mask] = 1;
        }

        // DP over columns
        for (int col = 1; col < n; ++col) {
            std::unordered_map<int, int> new_dp;
            for (const auto& [mask, count] : dp) {
                for (int next_mask : transitions[mask]) {
                    new_dp[next_mask] = (new_dp[next_mask] + count) % MOD;
                }
            }
            dp = std::move(new_dp);
        }

        // Sum all valid colorings
        int result = 0;
        for (const auto& [_, count] : dp) {
            result = (result + count) % MOD;
        }

        return result;
    }

private:
    // Generate all valid masks for a column
    void generateValidMasks(int m, int pos, int mask, std::vector<int>& masks) {
        if (pos == m) {
            masks.push_back(mask);
            return;
        }
        for (int color = 0; color < 3; ++color) {
            if (pos == 0 || ((mask >> ((pos - 1) * 2)) & 3) != color) {
                generateValidMasks(m, pos + 1, mask | (color << (pos * 2)), masks);
            }
        }
    }

    // Check if two masks can be adjacent columns
    bool isValidTransition(int mask1, int mask2, int m) {
        for (int i = 0; i < m; ++i) {
            if (((mask1 >> (i * 2)) & 3) == ((mask2 >> (i * 2)) & 3)) {
                return false;
            }
        }
        return true;
    }
};