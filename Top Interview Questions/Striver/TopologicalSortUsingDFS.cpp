class Solution 
{
	void findTopoSort(int node, vector<int>&vis, stack<int>&st, vector<int>adj[])
	{
    	vis[node] = 1;
		for (int i=0;i<adj[node].size();i++)
		{
			if (!vis[adj[node][i]]) 
			{
				findTopoSort(adj[node][i], vis, st, adj);
			}
		}
		st.push(node);
  	}
    vector<int>topoSort(int N, vector<int>adj[])
	{
    	stack<int>st;
		vector<int>vis(N, 0);
		for(int i=0;i<N;i++)
		{
			if(vis[i]==0)
			{
				findTopoSort(i, vis, st, adj);
			}
		}
		vector<int>ans;
		while (!st.empty())
		{
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}
};
