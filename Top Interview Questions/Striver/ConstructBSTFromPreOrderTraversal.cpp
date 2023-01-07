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
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        vector<int>inorder;
        inorder = preorder;
        sort(inorder.begin(), inorder.end());
        unordered_map<int,int>um;
        int n = inorder.size();
        for(int i=0;i<n;i++)
        {
            um[inorder[i]] = i;
        }
        int curr = 0;
        return helper(preorder, um, curr, 0, n-1);
    }

    TreeNode* helper(vector<int>& preorder, unordered_map<int,int>&um, int& curr, int start, int end)
    {
        if(start>end)
        {
            return nullptr;
        }
        int val = preorder[curr];
        TreeNode* node = new TreeNode(val);
        int index = um[val];
        curr++;
        node->left = helper(preorder,um,curr,start,index-1);
        node->right = helper(preorder,um,curr,index+1,end);
        return node;
    }
};