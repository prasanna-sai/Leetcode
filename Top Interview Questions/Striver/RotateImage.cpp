class Solution
{
    public:
        void rotate(vector<vector<int>>& v)
        {
            int i=0;
            int n = v.size();
            while(i<(n/2))
            {
                helper(v,i,n);
                i++;
            }
            return ;
        }
        //Helper function to rotate ith layer from outside of the square matrix
        void helper(vector<vector<int>>& v , int i , int n)
        {
            for(int j=i+1;j<n-i-1;j++)
            {
                swap(v[i][j] , v[j][n-i-1]); //Swap elements on top row and right column
                swap(v[n-i-1][j] , v[j][i]); //Swap elements on bottom row and left column
            }
            for(int j=i+1;j<n-i-1;j++)
            {
                swap(v[i][j] , v[n-i-1][n-1-j]); //Swap elements on top row and bottom row
            }
            //Swap the 4 corner elements to put them in correct position
            swap(v[i][i],v[i][n-i-1]);
            swap(v[n-i-1][n-i-1],v[n-i-1][i]);
            swap(v[i][i],v[n-i-1][n-i-1]);
            return;
        }
};


//Transpose and Reflect around the vertical axis

class Solution
{
    public:
        void rotate(vector<vector<int>>& v)
        {
            int n = v.size();
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    swap(v[i][j],v[j][i]);
                }
                for(int j=0;j<n/2;j++)
                {
                    swap(v[i][j],v[i][n-j-1]);
                }
            }
            return;
        }
        
};