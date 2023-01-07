class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<int>dp(V+1,INT_MAX);
        dp[0] = 0;
        sort(coins,coins+M);
        for(int i=1;i<V+1;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(i-coins[j] >= 0)
                {
                    if(dp[i-coins[j]] != INT_MAX)
                    {
                        dp[i] = min(dp[i],dp[i-coins[j]]+1);
                    }
                }
                else
                {
                    break;
                }
            }
        }
        if(dp[V] == INT_MAX)
        {
            return -1;
        }
        return dp[V];
	} 
	  
};