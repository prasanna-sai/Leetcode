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
    int prev = INT_MIN;
    int count = 0;
    bool isValidBST(TreeNode* root)
    {
        if(root == NULL)
        {
            return true;
        }
        bool left = isValidBST(root->left);
        if(root->val > prev || count == 0) // For the case where the leftmost leaf element is INT_MIN
        {
            count++;
            prev = root->val;
        }
        else
        {
            return false;
        }
        bool right = isValidBST(root->right);
        return left && right;
    }
};