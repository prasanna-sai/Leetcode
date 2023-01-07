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