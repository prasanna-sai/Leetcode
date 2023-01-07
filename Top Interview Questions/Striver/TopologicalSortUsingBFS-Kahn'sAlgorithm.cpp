class Solution
{
	public:
		vector<int> topoSort(int V, vector<int> adj[])
		{
			vector<int>indegree(V,0);
			for (int i = 0; i < V; i++)
			{
				for(int j=0;j<adj[i].size();j++)
				{
					indegree[adj[i][j]]++;
				}
			}
			queue<int> q;
			for (int i = 0; i < V; i++)
			{
				if (indegree[i] == 0)
				{
					q.push(i);
				}
			}
			vector<int> ans;
			while (!q.empty())
			{
				int i = q.front();
				q.pop();
				ans.push_back(i);
				for(int j=0;j<adj[i].size();j++)
				{
					indegree[adj[i][j]]--;
					if (indegree[adj[i][j]] == 0) 
					{
						q.push(adj[i][j]);
					}
				}
			}
			return ans;
		}
};
