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
			int cnt=0;
			while (!q.empty())
			{
				int i = q.front();
				q.pop();
				cnt++;
				for(int j=0;j<adj[i].size();j++)
				{
					indegree[adj[i][j]]--;
					if (indegree[adj[i][j]] == 0) 
					{
						q.push(it);
					}
				}
			}
            if(cnt == V)
            {
                return false;
            }
			return true;
		}
};
