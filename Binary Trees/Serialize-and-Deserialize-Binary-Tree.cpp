/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return \null\;
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                res += to_string(node->val) + \,\;
                q.push(node->left);
                q.push(node->right);
            } else {
                res += \null,\;
            }
        }
        res.pop_back(); // remove trailing comma
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == \null\) return nullptr;
        vector<string> vals;
        stringstream ss(data);
        string val;
        while (getline(ss, val, ',')) {
            vals.push_back(val);
        }

        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < vals.size()) {
            TreeNode* node = q.front(); q.pop();
            if (vals[i] != \null\) {
                node->left = new TreeNode(stoi(vals[i]));
                q.push(node->left);
            }
            ++i;
            if (i < vals.size() && vals[i] != \null\) {
                node->right = new TreeNode(stoi(vals[i]));
                q.push(node->right);
            }
            ++i;
        }
        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));