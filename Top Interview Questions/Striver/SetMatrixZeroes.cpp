class Solution {
public:
    void setZeroes(vector<vector<int>>& v)
    {
        //store states of each row in the first of that row, and store states of each column in the first of that column. 
        //Because the state of row0 and the state of column0 would occupy the same cell, 
        //I let it be the state of row0, and use another variable "c1" for column0.
        int m = v.size();
        int n = v[0].size();
        int c1 = 0;
        for(int i=0;i<m;i++)
        {
            if(v[i][0] == 0)
            {
                c1 = 1;
            }
            for(int j=1;j<n;j++)
            {
                if(v[i][j] == 0)
                {
                    v[i][0] = 0;
                    v[0][j] = 0;
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(v[i][0] == 0 || v[0][j] == 0)
                {
                    v[i][j] = 0;
                }
            }
        }
        if(v[0][0] == 0)
        {
            for(int i=0;i<n;i++)
            {
                v[0][i] = 0;
            }
        }
        if(c1)
        {
            for(int i=0;i<m;i++)
            {
                v[i][0] = 0;
            }
        }
        return;
    }
};


class Solution {
public:
    void setZeroes(vector<vector<int>>& v)
    {
        int m = v.size();
        int n = v[0].size();
        int isFirstColHasZero = 0;
        int isFirstRowHasZero = 0;
        for(int i=0;i<n;i++)
        {
            if(v[0][i] == 0)
            {
                isFirstRowHasZero = 1;
                break;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(v[i][0] == 0)
            {
                isFirstColHasZero = 1;
                break;
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(v[i][j] == 0)
                {
                    v[i][0] = 0;
                    v[0][j] = 0;
                }
            }
        }

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(v[i][0] == 0 || v[0][j] == 0)
                {
                    v[i][j] = 0;
                }
            }
        }
        if(isFirstRowHasZero)
        {
            for(int i=0;i<n;i++)
            {
                v[0][i] = 0;
            }
        }
        if(isFirstColHasZero)
        {
            for(int i=0;i<m;i++)
            {
                v[i][0] = 0;
            }
        }
        return;
    }
};