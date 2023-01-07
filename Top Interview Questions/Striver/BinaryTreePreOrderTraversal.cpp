class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
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
        ans.push_back(node->val);
        helper(node->left, ans);
        helper(node->right, ans);
        return;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        stack<TreeNode*> st;
        while(root || !st.empty())
        {
            if(root)
            {
                ans.push_back(root->val);
                if(root->right)
                {
                    st.push(root->right);
                }
                root = root->left;
            }
            else
            {
                root = st.top();
                st.pop();
            }
        }
        return ans;
    }
};