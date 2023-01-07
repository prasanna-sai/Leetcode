class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
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
        helper(node->right, ans);
        ans.push_back(node->val);
        return;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* lastNode = NULL;
        while(root || !st.empty())
        {
            if(root)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                TreeNode* temp = st.top();
                if(temp->right && temp->right != lastNode)
                {
                    root = temp->right;
                }
                else
                {
                    ans.push_back(temp->val);
                    lastNode = temp;
                    st.pop();
                }
            }
        }
        return ans;
    }
};