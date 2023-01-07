class Solution {
public:
    bool isBipartite(vector<vector<int>>& v)
    {
        int n = v.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++)
        {
            if(col[i] == -1)
            {
                if(!helper(v,i,col,0))
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool helper(vector<vector<int>>&v, int node, vector<int>&col, int currCol)
    {
        col[node] = currCol;
        queue<int>q;
        q.push(node);
        while(!q.empty())
        {
            int ft = q.front();
            q.pop();

            for(int i=0; i<v[ft].size();i++)
            {
                if(col[v[ft][i]] == -1)
                {
                    col[v[ft][i]] = !col[ft];
                    q.push(v[ft][i]);
                }
                else if(col[v[ft][i]] == col[ft])
                {
                    return false;
                }
            }
        }
        return true;
    }
};