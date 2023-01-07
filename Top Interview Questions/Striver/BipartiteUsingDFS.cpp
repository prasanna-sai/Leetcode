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
        for(int i=0; i<v[node].size();i++)
        {
            if(col[v[node][i]] == -1)
            {
                if(!helper(v,v[node][i],col,!currCol))
                {
                    return false;
                }
            }
            else if(col[v[node][i]] == currCol)
            {
                return false;
            }
        }
        return true;
    }
};