class Solution {
public:
    int coinChange(vector<int>& coins, int V)
    {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<int>dp(V+1,INT_MAX);
        dp[0] = 0;
        for(int i=0;i<=V;i++)
        {
            for(auto coin:coins)
            {
                if(coin<=i)
                {
                    if(dp[i-coin] != INT_MAX)
                    {
                        dp[i] = min(dp[i], dp[i-coin]+1);
                    }
                }
                else
                {
                    break;
                }
            }
        }
        if(dp[V] != INT_MAX)
        {
            return dp[V];
        }
        return -1;
    }
};