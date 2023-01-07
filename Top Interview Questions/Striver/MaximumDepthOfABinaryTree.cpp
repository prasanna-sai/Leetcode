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
            int ans = max(maxDepth(root->left)+1 , maxDepth(root->right)+1);
            return ans;
        }
        
};


class Solution
{
    public:
        int maxDepth(TreeNode* root)
        {
            if(!root)
            {
                return 0;
            }
            queue<TreeNode*>q;
            q.push(root);
            int ans = 0;
            while(!q.empty())
            {
                ans++;
                int n=q.size();
                for(int i=0;i<n;i++)
                {
                    TreeNode* p = q.front();
                    q.pop();
                    if(p->left) q.push(p->left);
                    if(p->right) q.push(p->right);
                }
            }
            return ans;
        }
        
};
