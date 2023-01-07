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
class Structure
{
    public:
        int maxi;
        int mini;
        int sum;
        bool isBST;
};
Structure solve(TreeNode* root, int& ans)
{
    if(!root)
    {
        return {INT_MIN, INT_MAX, 0, true};
    }
    Structure left = solve(root->left, ans);
    Structure right = solve(root->right, ans);
    Structure currNode;
    currNode.sum = left.sum + right.sum + root->val;
    currNode.maxi = max(root->val, right.maxi);
    currNode.mini = min(root->val, left.mini);
    if(left.isBST && right.isBST && (root->val>left.maxi && root->val<right.mini)){
        currNode.isBST= true;
        ans = max(ans,currNode.sum);
    }
    else{
       currNode.isBST = false;
    }
    return currNode;
}
class Solution
{
    public:
        int maxSumBST(TreeNode* root)
        {
            int ans = 0;
            Structure x =solve(root, ans);
            return ans;
        }
};