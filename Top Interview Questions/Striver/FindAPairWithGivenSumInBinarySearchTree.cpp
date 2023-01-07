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
    bool findTarget(TreeNode* root, int k)
    {
        unordered_set<int>us;
        return helper(root, k, us);  
    }

    bool helper(TreeNode* root, int k, unordered_set<int>& us)
    {
        if(!root)
        {
            return false;
        }
        int val = root->val;
        if(us.count(k-val))
        {
            return true;
        }
        us.insert(val);
        return helper(root->left, k, us) | helper(root->right, k, us);
    }
};