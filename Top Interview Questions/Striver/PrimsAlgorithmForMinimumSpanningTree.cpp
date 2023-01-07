class Solution
{
	public:
	    //Function to find sum of weights of edges of the Minimum Spanning Tree.
        int spanningTree(int V, vector<vector<int>> adj[])
        {
            int ans = 0;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
            vector<int>vis(V,0);
            pq.push(make_pair(0,0));
            while(!pq.empty())
            {
                int weight = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                if(!vis[node])
                {
                    vis[node] = 1;
                    ans = ans + weight;
                    for(int i=0;i<adj[node].size();i++)
                    {
                        int adjNode = adj[node][i][0];
                        int adjWeight = adj[node][i][1];
                        if(!vis[adjNode])
                        {
                            pq.push(make_pair(adjWeight, adjNode));
                        }
                    }
                }
            }
            return ans;
        }
};