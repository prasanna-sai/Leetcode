class Solution {
public:

    bool isCycle(int V, vector<int> adj[]) 
    {
        // initialise them as unvisited 
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(helper(i, adj, vis)) return true; 
            }
        }
        return false; 
    }
    bool helper(int src, vector<vector<int>>& v, int vis[])
    {
        vis[src] = 1;
		queue<pair<int,int>>q;
		q.push({src,-1});
		while(!q.empty())
		{
			int curr = q.front().first;
            int parent = q.front().second;
			q.pop();
            for(int i=0;i<adj[curr].size();i++)
            {
                if(!vis[adj[curr][i]])
                {
                    vis[adj[curr][i]] = 1;
                    q.push({adj[curr][i],curr});
                }
                else if(parent != adj[curr][i])
                {
                    return true;
                }
            }
        }
        return false;
    }
};