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