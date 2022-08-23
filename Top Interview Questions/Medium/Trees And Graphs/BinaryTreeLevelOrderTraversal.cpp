/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Basic Recursive solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int>ans;
        helper(ans,root);
        return ans;
    }
    void helper(vector<int>& ans , TreeNode* curr)
    {
        if(curr == nullptr)
        {
            return;
        }
        helper(ans , curr->left);
        ans.push_back(curr->val);
        helper(ans , curr->right);
        return;
    }
};

//Iterative Solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> nodes;
        stack<TreeNode*> todo;
        while (root || !todo.empty())
        {
            while (root)
            {
                todo.push(root);
                root = root -> left;
            }
            root = todo.top();
            todo.pop();
            nodes.push_back(root -> val);
            root = root -> right;
        }
        return nodes;
    }
};