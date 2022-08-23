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
    TreeNode* sortedArrayToBST(vector<int>& v)
    {
        int n = v.size();
        return helper(v, 0, n-1);
    }
    //Divide and Conquer technique
    TreeNode* helper(vector<int> v, int start, int end)
    {
        if(start>end)
        {
            return NULL;
        }
        if(start == end)
        {
            return new TreeNode(v[start]);
        }
        else if (start + 1 == end)
        {
            return new TreeNode(v[end], new TreeNode(v[start]), nullptr);
        }
        else if (start + 2 == end)
        {
            return new TreeNode(v[start+1], new TreeNode(v[start]), new TreeNode(v[end]));
        }
        else
        {
            int m = (start + end) / 2;
            return new TreeNode(v[m], helper(v, start, m-1), helper(v, m+1, end));
        }
    }
};