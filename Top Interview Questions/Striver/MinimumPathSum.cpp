class Solution
{
    public:
        int minPathSum(vector<vector<int>>& v)
        {
            int r = v.size();
            int c = v[0].size();
            for(int i=1;i<r;i++)
            {
                v[i][0] += v[i-1][0];
            }
            for(int i=1;i<c;i++)
            {
                v[0][i] += v[0][i-1];
            }
            for(int i=1;i<r;i++)
            {
                for(int j=1;j<c;j++)
                {
                    v[i][j] += min(v[i-1][j],v[i][j-1]);
                }
            }
            return v[r-1][c-1];
        }
};