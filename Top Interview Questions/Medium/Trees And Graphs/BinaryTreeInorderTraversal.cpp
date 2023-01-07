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
        vector<int> ans;
        stack<TreeNode*> st;
        while (root || st.empty() == false)
        {
            // Reach the left most Node of the current node
            while (root)
            {
                st.push(root);
                root = root -> left;
            }
            //Current must be NULL at this point
            root = st.top();
            st.pop();
            ans.push_back(root -> val);
            //we have visited the node and its left subtree.  Now, it's right subtree's turn
            root = root -> right;
        }
        return ans;
    }
};

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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int>ans;
        helper(root, ans);
        return ans;
    }
    void helper(TreeNode* node, vector<int>& ans)
    {
        if(!node)
        {
            return;
        }
        helper(node->left, ans);
        ans.push_back(node->val);
        helper(node->right, ans);
        return;
    }
};