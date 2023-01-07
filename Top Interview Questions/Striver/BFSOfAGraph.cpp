class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
		queue<int>q;
		q.push(0);
		vector<int>ans;
		while(!q.empty())
		{
			int temp = q.front();
			q.pop();
			if(!vis[temp])
			{
				vis[temp] = 1;
				ans.push_back(temp);
				for(int i=0;i<adj[temp].size();i++)
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