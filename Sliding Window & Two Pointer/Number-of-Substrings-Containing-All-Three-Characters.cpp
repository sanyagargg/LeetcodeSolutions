class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3, 0);
        int res = 0, left = 0;
        for (int right = 0; right < s.length(); ++right) {
            count[s[right] - 'a']++;
            while (count[0] && count[1] && count[2]) {
                count[s[left++] - 'a']--;
            }
            res += left;
        }
        return res;
    }
};
