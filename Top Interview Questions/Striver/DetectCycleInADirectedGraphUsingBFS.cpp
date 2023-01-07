class Solution
{
	public:
		bool hasCycle(int V, vector<int> adj[])
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
				for(int j=0;j<adj[i].size();j++)
				{
					indegree[adj[i][j]]--;
					if (indegree[adj[i][j]] == 0) 
					{
						q.push(it);
					}
				}
			}
            if(ans.size() == V)
            {
                return false;
            }
			return true;
		}
};
