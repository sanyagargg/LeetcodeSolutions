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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i)
            inorderMap[inorder[i]] = i;
        int preIndex = 0;
        return build(preorder, inorderMap, preIndex, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inorderMap, int& preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(preorder, inorderMap, preIndex, inStart, inorderMap[rootVal] - 1);
        root->right = build(preorder, inorderMap, preIndex, inorderMap[rootVal] + 1, inEnd);
        return root;
    }
};
