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
    int widthOfBinaryTree(TreeNode* root)
    {
        queue<pair<TreeNode*,int>>q;
        q.push(make_pair(root,0));
        long long int ans = 0;
        while(!q.empty())
        {
            long long int n = q.size();
            long long int lt,rt;
            //long long int start = q.front().second;
            for(int i=0;i<n;i++)
            {
                TreeNode* x = q.front().first;
                long long int val = q.front().second;
                //long long int val = q.front().second - start; -> can use this to maintain from beginning in case of overflow
                q.pop();
                if(i==0)
                {
                    lt = val;
                }
                if(i==n-1)
                {
                    rt = val;
                }
                if(x->left)
                {
                    q.push(make_pair(x->left,2*val+1));
                }
                if(x->right)
                {
                    q.push(make_pair(x->right,2*val+2));
                }
            }
            ans = max(ans,rt-lt+1);
        } 
        return ans;
    }
};