class Solution
{
    public:
        int matrixMultiplication(int N, int arr[])
        {
            vector<vector<int>>dp(N,vector<int>(N,-1));
            return helper(arr, 1, N-1, dp);
        }

        int helper(int* arr, int i, int j, vector<vector<int>>& dp )
        {
            if(i==j)
            {
                return 0;
            }
            if(dp[i][j] != -1)
            {
                return dp[i][j];
            }
            
            int ans = INT_MAX;
            for(int k = i; k<= j-1; k++){
                
                int x = helper(arr,i,k,dp) + helper(arr, k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
                
                ans = min(x,ans);
                
            }
            dp[i][j] = ans;
            return ans;
        }
};