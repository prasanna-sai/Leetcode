class DisjointSet
{
    public:
        vector<int>parent, size;
        DisjointSet(int n)
        {
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++)
            {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUltimateParent(int node)
        {
            if(parent[node] == node)
            {
                return node;
            }
            node = findUltimateParent(parent[node]);
            return node;
        }

        void UnionBySize(int u, int v)
        {
            int ultimateParentOfU = findUltimateParent(u);
            int ultimateParentOfV = findUltimateParent(v);

            if(ultimateParentOfU == ultimateParentOfV)
            {
                return;
            }
            if(size[ultimateParentOfU] >= size[ultimateParentOfV])
            {
                parent[ultimateParentOfV] = ultimateParentOfU;
                size[ultimateParentOfU] += size[ultimateParentOfV];
                return;
            }
            parent[ultimateParentOfU] = ultimateParentOfV;
            size[ultimateParentOfV] += size[ultimateParentOfU];
            return;
        }
};

class Solution
{
	public:
	    //Function to find sum of weights of edges of the Minimum Spanning Tree.
        int spanningTree(int V, vector<vector<int>> adj[])
        {
            int ans = 0;
            vector<pair<int,pair<int,int>>>edges;
            for(int i=0;i<V;i++)
            {
                for(int j=0;j<adj[i].size();j++)
                {
                    edges.push_back(make_pair(adj[i][j][1], make_pair(i,adj[i][j][0])));
                }
            }
            DisjointSet ds(V);
            sort(edges.begin(), edges.end());

            for(int i=0;i<edges.size();i++)
            {
                if(ds.findUltimateParent(edges[i].second.first) != ds.findUltimateParent(edges[i].second.second))
                {
                    ans += edges[i].first;
                    ds.UnionBySize(edges[i].second.first, edges[i].second.second);
                }
            }
            return ans;
        }
};