/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> result;
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool leftToRight = true;

        while (!dq.empty()) {
            int levelSize = dq.size();
            vector<int> level;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = dq.front();
                dq.pop_front();
                level.push_back(node->val);
                if (node->left) dq.push_back(node->left);
                if (node->right) dq.push_back(node->right);
            }
            if (!leftToRight) reverse(level.begin(), level.end());
            result.push_back(level);
            leftToRight = !leftToRight;
        }
        return result;
    }
};
