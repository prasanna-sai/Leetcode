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
    int kthSmallest(TreeNode* root, int k)
    {
        int count = 0, ans = 0;
        helper(root, count, ans, k);
        return ans;
    }
    void helper(TreeNode* node, int& count, int& ans, int k)
    {
        if(!node || count>k) return;
        helper(node->left, count, ans, k);
        count++;
        if(count == k )
        {
            ans = node->val;
            return;
        }
        helper(node->right, count, ans, k);
    }
};