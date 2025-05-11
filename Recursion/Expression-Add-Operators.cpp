class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.empty()) return ans;
        dfs(num, target, 0, \\, 0, 0, ans);
        return ans;
    }

private:
    void dfs(const string& num, int target, int pos, string expr, long prev, long curr, vector<string>& ans) {
        if (pos == num.size()) {
            if (curr == target) ans.push_back(expr);
            return;
        }

        for (int len = 1; len <= num.size() - pos; ++len) {
            string str = num.substr(pos, len);
            if (str[0] == '0' && len > 1) break;  // Skip numbers with leading zeros
            long n = stol(str);

            if (pos == 0) {
                dfs(num, target, pos + len, str, n, n, ans);  // First number, no operator
            } else {
                dfs(num, target, pos + len, expr + \+\ + str, n, curr + n, ans);
                dfs(num, target, pos + len, expr + \-\ + str, -n, curr - n, ans);
                dfs(num, target, pos + len, expr + \*\ + str, prev * n, curr - prev + prev * n, ans);
            }
        }
    }
};
