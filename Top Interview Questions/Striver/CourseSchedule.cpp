class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) 
    {
        unordered_map<int,vector<int>> adj;
        for(auto edge : edges){
            int u= edge[0]; int v= edge[1];
            adj[v].push_back(u);
        } 
        vector<int>vis(V,0),dfsVis(V,0);
        for(int i=0;i<V;i++) {
            if(!vis[i]) 
            {
                if(helper(i, adj, vis, dfsVis))
                {
                    return false;
                }
            }
        }
        return true;     
    }

    bool helper(int src, unordered_map<int,vector<int>>& adj, vector<int>& vis, vector<int>& dfsVis)
    {
        vis[src] = 1;
        dfsVis[src] = 1;
        for(int i=0;i<adj[src].size();i++)
        {
            if(!vis[adj[src][i]])
            {
                if(helper(adj[src][i],adj,vis,dfsVis))
                {
                    return true;
                }
            }
            else if(dfsVis[adj[src][i]])
            {
                return true;
            }
        }
        dfsVis[src] = 0;
        return false;
    }
};