//Function to return a list containing the bottom view of the given tree.

class Solution
{
	public:
		vector <int> bottomView(Node *root)
		{
        	unordered_map<int,int>um;
			vector<int>ans;
			int start = 0;
			queue<pair<Node*,int>>q;
			q.push(make_pair(root,0));
			while(!q.empty())
			{
				Node* temp = q.front().first;
				int dis = q.front().second;
				q.pop();
				um[dis] = temp->data;
				start = min(start,dis);
				if(temp->left)
				{
					q.push(make_pair(temp->left,dis-1));
				}
				if(temp->right)
				{
					q.push(make_pair(temp->right,dis+1));
				}
			}
			while(um.count(start))
			{
				ans.push_back(um[start]);
				start++;
			}
			return ans;
    	}
};