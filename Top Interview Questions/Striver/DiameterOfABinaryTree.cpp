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
    int diameterOfBinaryTree(TreeNode* root)
    {
        int ans = 0;
        int val = helper(root,ans);
        return ans;
    }
    int helper(TreeNode* node, int& val)
    {
        if(!node) return 0;
        int leftHeight = helper(node->left, val);
        int rightHeight = helper(node->right, val);
        val = max(val,leftHeight+rightHeight);
        return 1+max(leftHeight,rightHeight);
    }
};