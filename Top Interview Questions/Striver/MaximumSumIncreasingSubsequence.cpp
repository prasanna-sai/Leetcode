class Solution{
	public:
		int maxSumIS(int v[], int n)  
		{
	        vector<int>dp(n,0);
	        for(int i=0;i<n;i++)
	        {
	            dp[i] = v[i];
	        }
			for(int i=1;i<n;i++)
			{
				for(int j=0;j<i;j++)
				{
					if(v[i] > v[j])
					{
						dp[i] = max(dp[i], dp[j] + v[i]);
					}
				}
			}
			int ans = 0;
			for(int i=0;i<n;i++)
			{
			    ans = max(ans,dp[i]);
			}
			return ans;
		}  
};