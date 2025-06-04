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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return build(preorder, index, INT_MAX);
    }

private:
    TreeNode* build(const vector<int>& preorder, int& index, int bound) {
        if (index == preorder.size() || preorder[index] > bound) return nullptr;
        
        int val = preorder[index++];
        TreeNode* root = new TreeNode(val);
        root->left = build(preorder, index, val);
        root->right = build(preorder, index, bound);
        return root;
    }
};
