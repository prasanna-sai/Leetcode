/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //Inorder travel the BST and find the kth element from the beginning
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        vector<int>v;
        helper(v,root);
        int n = v.size();
        return v[k-1];
    }
    void helper(vector<int>& v , TreeNode* Node)
    {
        if(Node == nullptr)
        {
            return;
        }
        helper(v,Node->left);
        v.push_back(Node->val);
        helper(v,Node->right);
        return;
    }
};