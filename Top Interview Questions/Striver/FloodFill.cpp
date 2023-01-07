class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& v, int sr, int sc, int color)
    {
        if(v[sr][sc] == color)
        {
            return v;
        }
        int clr = v[sr][sc];
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int row[] = {0,0,-1,1}, col[] = {-1,1,0,0};
        while(!q.empty())
        {
            int r = q.front().first, c = q.front().second;
            q.pop();
            vis[r][c] = 1;
            v[r][c] = color;
            for(int i=0;i<4;i++)
            {
                int x = r+row[i], y = c+col[i];
                if(x>=0 && x<m && y>=0 && y<n && v[x][y] == clr && !vis[x][y])
                {
                    vis[x][y] = 1;
                    q.push(make_pair(x,y));
                }
            }
        }
        return v;
    }
};