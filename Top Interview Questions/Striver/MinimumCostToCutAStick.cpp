class Solution
{
    public:
        int minCost(int n, vector<int>& cuts)
        {
            sort(cuts.begin(), cuts.end());
            cuts.insert(cuts.begin(),0);
            cuts.push_back(n);
            int x = cuts.size();
            vector<vector<int>>dp(x,vector<int>(x,-1));
            return helper(1,x-2,cuts,dp);
        }

        int helper(int i, int j, vector<int>& cuts, vector<vector<int>>& dp)
        {
            if(i>j) return 0;
            if(dp[i][j] != -1)
            {
                return dp[i][j];
            }
            int ans = INT_MAX;
            for(int k=i;k<=j;k++)
            {
                int temp = cuts[j+1] - cuts[i-1] + helper(i,k-1,cuts,dp) + helper(k+1,j, cuts, dp);
                ans = min(ans, temp);
            }
            dp[i][j] = ans;
            return ans;
        }
};