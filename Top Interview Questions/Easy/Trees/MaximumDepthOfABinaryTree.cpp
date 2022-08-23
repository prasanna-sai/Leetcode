/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    public:
        int maxDepth(TreeNode* root)
        {
            if(root == nullptr)
            {
                return 0;
            }
            //recursive calling of function
            int ans = max(maxDepth(root->left)+1 , maxDepth(root->right)+1);
            return ans;
        }
        
};
