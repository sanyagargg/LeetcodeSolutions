class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> count(26, 0);
        int maxCount = 0, left = 0, maxLength = 0;

        for (int right = 0; right < s.size(); ++right) {
            maxCount = std::max(maxCount, ++count[s[right] - 'A']);
            if (right - left + 1 - maxCount > k) {
                --count[s[left] - 'A'];
                ++left;
            }
            maxLength = std::max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};