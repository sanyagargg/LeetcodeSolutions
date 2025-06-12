class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parent;      // email -> parent email
        unordered_map<string, string> emailToName; // email -> username

        // 1. Initialize parent map and emailToName
        for (const auto& acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); ++i) {
                parent[acc[i]] = acc[i];
                emailToName[acc[i]] = name;
            }
        }

        // 2. Union emails in same account
        for (const auto& acc : accounts) {
            string root = find(acc[1], parent);
            for (int i = 2; i < acc.size(); ++i) {
                parent[find(acc[i], parent)] = root;
            }
        }

        // 3. Group emails by root parent
        unordered_map<string, set<string>> unions;
        for (const auto& [email, _] : parent) {
            string root = find(email, parent);
            unions[root].insert(email);
        }

        // 4. Build result
        vector<vector<string>> result;
        for (const auto& [root, emails] : unions) {
            vector<string> merged = {emailToName[root]};
            merged.insert(merged.end(), emails.begin(), emails.end());
            result.push_back(merged);
        }

        return result;
    }

private:
    string find(string email, unordered_map<string, string>& parent) {
        if (parent[email] != email)
            parent[email] = find(parent[email], parent);
        return parent[email];
    }
};
