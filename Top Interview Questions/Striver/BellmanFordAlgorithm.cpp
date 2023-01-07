class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S)
    {
        vector<int>ans(V,1e8);
        ans[S] = 0;
        int n = edges.size();
        for(int j=0;j<V-1;j++)
		{
			for(int i=0;i<n;i++)
        	{
				int u = edges[i][0];
				int v = edges[i][1];
				int w = edges[i][2];
				if(ans[u] != 1e8 && ans[u] + w < ans[v])
				{
					ans[v] = ans[u]+w;
				}
        	}
		}
		for(int i=0;i<n;i++)
		{
			int u = edges[i][0];
			int v = edges[i][1];
			int w = edges[i][2];
			if(ans[u] != 1e8 && ans[u] + w < ans[v])
			{
				return {-1};
			}
		}
		return ans;
    }
};