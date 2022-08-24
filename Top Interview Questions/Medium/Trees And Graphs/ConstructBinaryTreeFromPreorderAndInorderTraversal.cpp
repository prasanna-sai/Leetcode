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
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
        {
            unordered_map<int,int>um;
            int n = inorder.size();
            for(int i=0;i<n;i++)
            {
                um[inorder[i]] = i;
            }
            int curr = 0;
            return helper(preorder,inorder,um,curr,0,n-1);
        }
        TreeNode* helper(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>&um, int& curr, int start, int end)
        {
            if(start>end)
            {
                return NULL;
            }
            int val = preorder[curr];
            TreeNode* temp = new TreeNode(val);
            curr++;
            if(start == end)
            {
                return temp;
            }
            int index = um[val];
            temp->left = helper(preorder,inorder,um,curr,start,index-1);
            temp->right = helper(preorder,inorder,um,curr,index+1,end);
            return temp;
        }
    };