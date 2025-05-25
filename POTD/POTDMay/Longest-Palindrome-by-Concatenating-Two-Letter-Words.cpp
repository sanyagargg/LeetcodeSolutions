class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        int res = 0;
        bool hasCenter = false;

        for (const string& word : words) {
            count[word]++;
        }

        for (auto& [word, freq] : count) {
            string rev = string(word.rbegin(), word.rend());
            if (word == rev) {
                int pairs = freq / 2;
                res += pairs * 4;
                count[word] -= pairs * 2;
            } else if (word < rev && count.count(rev)) {
                int pairs = min(freq, count[rev]);
                res += pairs * 4;
                count[word] -= pairs;
                count[rev] -= pairs;
            }
        }

        for (auto& [word, freq] : count) {
            if (word[0] == word[1] && freq > 0) {
                res += 2;
                break;
            }
        }

        return res;
    }
};
