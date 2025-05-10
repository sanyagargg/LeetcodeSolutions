class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        dfs(s, 0, {}, ans);
        return ans;
    }

private:
    void dfs(const string& s, int start, vector<string> path, vector<vector<string>>& ans) {
        if (start == s.length()) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < s.length(); ++i) {
            string sub = s.substr(start, i - start + 1);
            if (isPalindrome(sub)) {
                path.push_back(sub);
                dfs(s, i + 1, path, ans);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }
};
