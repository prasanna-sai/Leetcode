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
class Solution
{
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root)
        {
            map<int,map<int,multiset<int>>>um;
			vector<vector<int>>ans;
			int start = 0;
			queue<pair<TreeNode*,pair<int,int>>>q;
			q.push(make_pair(root,make_pair(0,0)));
			while(!q.empty())
			{
				TreeNode* temp = q.front().first;
				int x = q.front().second.first;
                int y = q.front().second.second;
				q.pop();
				um[x][y].insert(temp->val);
				start = min(start,x);
				if(temp->left)
				{
					q.push(make_pair(temp->left,make_pair(x-1,y+1)));
				}
				if(temp->right)
				{
					q.push(make_pair(temp->right,make_pair(x+1,y+1)));
				}
			}
			for(auto p: um){
                vector<int> col;
                for(auto q: p.second)
                {
                    col.insert(col.end(), q.second.begin(), q.second.end());
                }
                ans.push_back(col);
            }
			return ans;
        }
};
