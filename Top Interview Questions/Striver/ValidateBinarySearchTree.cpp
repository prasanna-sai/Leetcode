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
    int val = INT_MIN;
    int count = 0;
    bool isValidBST(TreeNode* root)
    {
        if(!root) return true;
        bool isLeftValidBST = isValidBST(root->left);
        if(root->val > val || count == 0)
        {
            val = root->val;
            count++;
        }
        else
        {
            return false;
        }
        bool isRightValidBST = isValidBST(root->right);
        return isLeftValidBST && isRightValidBST;
    }
};