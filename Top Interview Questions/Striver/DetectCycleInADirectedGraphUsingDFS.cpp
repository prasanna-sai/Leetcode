class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& adj) 
    {
        vector<int>vis(V,0),dfsVis(V,0);
        for(int i=0;i<V;i++) {
            if(!vis[i]) 
            {
                if(helper(i, adj, vis, dfsVis))
                {
                    return true;
                }
            }
        }
        return false;     
    }

    bool helper(int src, vector<vector<int>>& adj, vector<int>& vis, vector<int>& dfsVis)
    {
        vis[src] = 1;
        dfsVis[src] = 1;
        for(int i=0;i<adj[src].size();i++)ś
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