class Solution {
public:
    void mark(int i,int j,vector<vector<char>>& grid)
    {
        int m = grid.size(),n=grid[0].size();
        if(i>=m || j>=n || i<0 || j<0) return ;
        if(grid[i][j]!='1') return;
        grid[i][j]='#';
        mark(i+1,j,grid);
        mark(i-1,j,grid);
        mark(i,j+1,grid);
        mark(i,j-1,grid);
    }

    //Basic DFS solution -> where we traverse the graph and mark all connected nodes as '#' and finally count the number of 1's
    int numIslands(vector<vector<char>>& grid)
    {
        if(grid.size()<1) return 0;
        int m = grid.size(),n=grid[0].size(),ret=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    mark(i,j,grid);
                    ret++;
                } 
            }
        }
        return ret;
    }
};