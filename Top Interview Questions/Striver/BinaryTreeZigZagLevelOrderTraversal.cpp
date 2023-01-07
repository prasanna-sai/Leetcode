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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if(!root)
        {
            return result;
        }
        deque<TreeNode*> q;
        q.push_back(root);
        int count = 1;
        while (!q.empty())
        {
            int n = q.size();
            vector<int>v;
            for (int i = 0; i < n; i++)
            {
                if(count%2 == 1)
                {
                    TreeNode* p = q.front();
                    q.pop_front();
                    v.push_back(p->val);
                    if(p->left) q.push_back(p->left);
                    if(p->right) q.push_back(p->right);
                }
                else
                {
                    TreeNode* p = q.back();
                    q.pop_back();
                    v.push_back(p->val);
                    if(p->right) q.push_front(p->right);
                    if(p->left) q.push_front(p->left);
                }
            }
            count++;
            result.push_back(v);
        }
        return result;    
    }
};