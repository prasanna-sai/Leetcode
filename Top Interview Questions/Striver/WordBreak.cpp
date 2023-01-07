class Solution
{
    public:
        bool wordBreak(string s, vector<string>& wordDict)
        {
            int n = s.length();
            unordered_set<string>us(wordDict.begin(), wordDict.end());
            vector<int>dp(n,-1);
            return helper(us, dp, s, 0);
        }

        bool helper(unordered_set<string>&us, vector<int>& dp, string s, int x)
        {
            if(x==s.length())
            {
                return true;
            }
            if(dp[x] != -1)
            {
                return dp[x];
            }
            for(int i=x;i<s.length();i++)
            {
                if(us.count(s.substr(x,i+1-x)) && helper(us, dp, s, i+1))
                {
                    return dp[x] = true;
                }
            }
            return dp[x] = false;
        }
};