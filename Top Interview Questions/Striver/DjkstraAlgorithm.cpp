class Solution
{
        public:
        //Function to find the shortest distance of all the vertices
        //from the source vertex S.
        vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
        {
            vector<int>ans(V,INT_MAX);
            ans[S] = 0;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
            pq.push(make_pair(0,S));
            while(!pq.empty())
            {
                int node = pq.top().second;
                int dis = pq.top().first;
                pq.pop();
                for(int i= 0;i<adj[node].size();i++)
                {
                    int adjNode = adj[node][i][0];
                    int weight = adj[node][i][1];
                    if(dis + weight < ans[adjNode])
                    {
                        ans[adjNode] = dis + weight;
                        pq.push({ans[adjNode], adjNode});
                    }
                }
            }
            return ans;
        }
};