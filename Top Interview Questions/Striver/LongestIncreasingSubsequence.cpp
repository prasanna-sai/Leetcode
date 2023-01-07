class Solution
{
    public:
        int lengthOfLIS(vector<int>& v)
        {
            int n = v.size();
            int ans = 0;
            vector<int>dp(n,1);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<i;j++)
                {
                    if(v[i] > v[j])
                    {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
                ans = max(ans,dp[i]);
            }
            return ans;
        }
};

class Solution
{
    public:
        int lengthOfLIS(vector<int>& v)
        {
            int n = v.size();
            vector<int>temp;
            temp.push_back(v[0]);
            for(int i=1;i<n;i++)
            {
                if(temp[temp.size()-1] < v[i])
                {
                    temp.push_back(v[i]);
                }
                else
                {
                    auto it = lower_bound(temp.begin(), temp.end(), v[i]);
                    *it = v[i];
                }
            }
            return temp.size();
        }
};