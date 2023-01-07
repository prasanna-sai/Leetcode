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
    int maxPathSum(TreeNode* root)
    {
        long long int ans = root->val;
        helper(root, ans);
        return ans;    
    }
    long long int helper(TreeNode* node, long long int& ans)
    {
        if(!node) return INT_MIN;
        long long int x = helper(node->left, ans);
        long long int y = helper(node->right, ans);
        ans = max(y+node->val,max(x+node->val,max(x+y+node->val,max(y,max(x,max(ans,(long long int)node->val))))));
        long long int val = node->val;
        if(x>0 && y>0)
        {
            val = val+max(x,y);
        } 
        else if(y>0)
        {
            val = val+y;
        }
        else if(x>0)
        {
            val = val+x;
        }
        return val;
    }
};

class Solution {
public:
    int maxPathSum(TreeNode* root)
    {
        int ans = root->val;
        helper(root, ans);
        return ans;    
    }
    int helper(TreeNode* node, int& ans)
    {
        if(!node) return 0;
        int x = max(helper(node->left, ans),0);
        int y = max(helper(node->right, ans),0);
        ans = max(ans, node->val+x+y);
        return node->val + max(x,y);
    }
};