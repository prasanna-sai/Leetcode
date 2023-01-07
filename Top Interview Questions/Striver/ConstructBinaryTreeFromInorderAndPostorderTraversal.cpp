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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        unordered_map<int,int>um;
        int n = inorder.size();
        for(int i=0;i<n;i++)
        {
            um[inorder[i]] = i;
        }
        int curr = n-1;
        return helper(postorder,um,curr,0,n-1);
    }

    TreeNode* helper(vector<int>& postorder, unordered_map<int,int>& um, int& curr, int start, int end)
    {
        if(curr<0 || start>end)
        {
            return nullptr;
        }
        int val = postorder[curr];
        TreeNode* node = new TreeNode(val);
        curr--;
        int index = um[val];
        node->right = helper(postorder, um, curr, index+1, end);
        node->left = helper(postorder, um, curr, start, index-1);
        return node;
    }
};