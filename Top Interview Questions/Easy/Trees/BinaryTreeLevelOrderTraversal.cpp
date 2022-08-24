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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>>ans;
        if(!root)
        {
            return ans;
        }
        pushValues(root, 0, ans);
        return ans;
    }
    //Level variable stores the level of the node and helps us in pushing node value to the correct index in the vector
    void pushValues(TreeNode* node, int level, vector<vector<int>>& v)
    {
        if(node == NULL)
        {
            return;
        }
        if(v.size()<level+1) //check if there is a vector of current level exists or not in the vector of vectors
        {
            vector<int>temp;
            temp.push_back(node->val);
            v.push_back(temp);
        }
        else
        {
            v[level].push_back(node->val);
        }
        pushValues(node->left, level+1, v);
        pushValues(node->right, level+1, v);
        return;
    }
};

//Iterative Solution using Queue Same approach

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int>v;
            for (int i = 0; i < n; i++)
            {
                TreeNode* p = q.front();
                q.pop();
                if (p != NULL)
                {
                    v.push_back(p->val);
                    q.push(p->left);
                    q.push(p->right);
                }
            }
            
            if (v.size() > 0) 
                result.push_back(v);
        }
        return result;
    }
};