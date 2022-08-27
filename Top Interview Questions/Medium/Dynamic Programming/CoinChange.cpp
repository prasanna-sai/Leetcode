class Solution
{
    public:
        int coinChange(vector<int>& coins, int amount)
        {
            //Straight Forward dp solution
            vector<int> dp(amount+1,INT_MAX);
            dp[0] = 0;
            sort(coins.begin(),coins.end());
            for(int i=0;i<=amount;i++)
            {
                for(auto coin:coins)
                {
                    if(coin<=i)
                    {
                        if(dp[i-coin]!=INT_MAX)
                        {   
                            dp[i] = min(dp[i],dp[i-coin]+1);
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
            return (dp[amount] == INT_MAX ? -1 : dp[amount]);
        }
};