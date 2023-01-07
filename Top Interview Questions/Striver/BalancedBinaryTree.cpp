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
    bool isBalanced(TreeNode* root)
    {
        if(!root) return true;
        return helper(root) != -1;
    }

    int helper(TreeNode* node)
    {
        if(!node)
        {
            return 0;
        }
        int leftHeight = helper(node->left);
        int rightHeight = helper(node->right);
        if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
        {
            return -1;
        }
        return 1 + max(leftHeight, rightHeight);
    }
};