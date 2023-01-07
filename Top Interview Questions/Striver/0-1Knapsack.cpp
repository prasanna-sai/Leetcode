class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return helper(wt, val, n-1, W, dp);
    }

    int helper(int* wt, int* val,  int n, int W, vector<vector<int>>& dp)
    {
        if(W == 0 || n < 0)
        {
            return 0;
        }
        if(dp[n][W] != -1)
        {
            return dp[n][W];
        }
        int notIncluded = helper(wt, val, n-1, W, dp);
        int included = 0;
        if(wt[n] <= W)
        {
            included = val[n] + helper(wt, val, n-1, W-wt[n], dp);
        }
        dp[n][W] = max(included, notIncluded);
        return dp[n][W];
    }
};

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        for(int i=wt[0];i<=W;i++)
        {
            dp[0][i] = val[0];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=W;j++)
            {
                int notIncluded = dp[i-1][j];
                int included = INT_MIN;
                if(wt[i] <= j)
                {
                    included = val[i] + dp[i-1][j-wt[i]];
                }
                dp[i][j] = max(included, notIncluded);
            }
        }
        return dp[n-1][W];
    }
};
