class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> count;
        int result = 0;

        for (auto& d : dominoes) {
            int a = d[0], b = d[1];
            int key = min(a, b) * 10 + max(a, b);  // Normalize the domino
            result += count[key];  // Add count of existing same-key dominoes
            count[key]++;
        }

        return result;
    }
};


//time: O(N)
//Space: O(1)