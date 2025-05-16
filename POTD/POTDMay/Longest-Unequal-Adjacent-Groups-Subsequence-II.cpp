class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);  // dp[i] = length of longest valid subsequence ending at i
        vector<int> parent(n, -1); // To reconstruct the path

        // Helper to compute hamming distance
        auto hamming = [](const string& a, const string& b) {
            if (a.length() != b.length()) return -1;
            int dist = 0;
            for (int i = 0; i < a.length(); ++i) {
                if (a[i] != b[i]) ++dist;
            }
            return dist;
        };

        // Build dp[i] by checking all j < i
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] &&
                    words[i].length() == words[j].length() &&
                    hamming(words[i], words[j]) == 1) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
        }

        // Find the index with the maximum dp value
        int maxLen = 0, lastIndex = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct the longest valid subsequence
        vector<string> result;
        while (lastIndex != -1) {
            result.push_back(words[lastIndex]);
            lastIndex = parent[lastIndex];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
