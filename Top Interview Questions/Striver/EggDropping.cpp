class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return helper(dp,n,k);
    }

    int helper(vector<vector<int>>&dp, int n, int k)
    {
        if(n==1)
        {
            return k;
        }
        if(k==0 || k==1)
        {
            return k;
        }
        if(dp[n][k] != -1)
        {
            return dp[n][k];
        }
        int ans = INT_MAX;
        for(int i=1;i<=k;i++)
        {
            int x = 1 + max(helper(dp,n-1,i-1), helper(dp,n,k-i));
            ans = min(ans, x);
        }
        dp[n][k] = ans;
        return ans;
    }
};