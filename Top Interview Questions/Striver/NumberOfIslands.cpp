class Solution
{
    public:
        int x[4] = {-1,1,0,0};
        int y[4] = {0,0,-1,1};
        int m,n;
        int numIslands(vector<vector<char>>& v)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            int ans = 0;
            m = v.size();
            n = v[0].size();
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(v[i][j] == '1')
                    {
                        v[i][j] = '2';
                        helper(i,j,v);
                        ans++;
                    }
                }
            }
            return ans;
        }

        void helper(int i, int j, vector<vector<char>>& v)
        {
            for(int k=0;k<4;k++)
            {
                int nx = i + x[k];
                int ny = j + y[k];
                if(isValidIndex(nx,ny) && v[nx][ny] == '1')
                {
                    v[nx][ny] = '2';
                    helper(nx,ny,v);
                }
            }
        }

        bool isValidIndex(int i, int j)
        {
            if(i<m && i>=0 && j<n && j>=0)
            {
                return true;
            }
            return false;
        }
};