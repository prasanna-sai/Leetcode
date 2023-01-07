class Solution {
  public:
    vector<vector<int>> Paths(Node* root)
    {
        vector<vector<int>>ans;
        vector<int>curr;
        helper(ans, curr, root);
        return ans;
    }
    void helper(vector<vector<int>>&ans, vector<int>v, Node* curr)
    {
        v.push_back(curr->data);
        if(!curr->left && !curr->right)
        {
            ans.push_back(v);
            return;
        }
        if(curr->left)
        {
            helper(ans, v, curr->left);
        }
        if(curr->right)
        {
            helper(ans, v, curr->right);
        }
    }
};