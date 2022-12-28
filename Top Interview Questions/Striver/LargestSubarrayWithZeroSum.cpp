class Solution
{
    public:
        int maxLen(vector<int>&v, int n)
        {   
            unordered_map<int,int>um;
            int sum = 0;
            int ans = 0;
            for(int i=0;i<n;i++)
            {
                sum += v[i];
                if(sum == 0)
                {
                    ans = i+1;
                }
                if(um.find(sum) != um.end())
                {
                    ans = max(ans,i-um[sum])
                }
                else
                {
                    um[sum] = i;
                }
            }
            return ans;
        }
};