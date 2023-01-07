class Solution {
public:
    int orangesRotting(vector<vector<int>>& v)
    {
        int m = v.size(), n = v[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));

        int row[] = {0,0,-1,1}, col[] = {-1,1,0,0};
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j] == 2)
                {
                    q.push(make_pair(make_pair(i,j),0));
                }
            }
        }
        int ans = 0;
        while(!q.empty())
        {
            int r = q.front().first.first, c = q.front().first.second, t = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x = r+row[i], y = c+col[i];
                if(x>=0 && x<m && y>=0 && y<n && v[x][y] == 1 && !vis[x][y])
                {
                    vis[x][y] = 1;
                    q.push(make_pair(make_pair(x,y),t+1));
                }
            }
            ans = t;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j] == 1 && !vis[i][j])
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};