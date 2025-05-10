class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> result;
        string combination;
        vector<string> phoneMap = {\\,    \\,    \abc\,  \def\, \ghi\,
                                   \jkl\, \mno\, \pqrs\, \tuv\, \wxyz\};
        backtrack(digits, 0, combination, result, phoneMap);
        return result;
    }

private:
    void backtrack(const string& digits, int index, string& combination, vector<string>& result, const vector<string>& phoneMap) {
        if (index == digits.size()) {
            result.push_back(combination);
            return;
        }
        int digit = digits[index] - '0';
        for (char c : phoneMap[digit]) {
            combination.push_back(c);
            backtrack(digits, index + 1, combination, result, phoneMap);
            combination.pop_back();
        }
    }
};
