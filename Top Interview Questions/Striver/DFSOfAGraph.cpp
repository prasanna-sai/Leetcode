class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int>vis(V,0);
		stack<int>q;
		q.push(0);
		vector<int>ans;
		while(!q.empty())
		{
			int temp = q.top();
			q.pop();
			if(!vis[temp])
			{
				vis[temp] = 1;
				ans.push_back(temp);
				for(int i=adj[temp].size()-1;i>=0;i--)
				{
					if(!vis[adj[temp][i]])
					{
						q.push(adj[temp][i]);
					}
				}
			}
		}
		return ans;
    }
};