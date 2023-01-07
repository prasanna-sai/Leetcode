class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int ans = 0;
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(text1[i] == text2[j])
                {
                    dp[i+1][j+1] = dp[i][j] + 1;
                }
                else
                {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[m][n];
    }
};


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(text1, text2, dp, m-1, n-1);
    }

    int helper(string& text1, string& text2, vector<vector<int>>& dp, int i, int j)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(text1[i] == text2[j])
        {
            dp[i][j] = 1 + helper(text1, text2, dp, i-1, j-1);
        }
        else
        {
            dp[i][j] = max(helper(text1, text2, dp, i-1, j), helper(text1, text2, dp, i, j-1));
        }
        return dp[i][j];
    }
    
};