class Solution
{
    public:
        int maxProfit(vector<int>& v)
        {
            int n = v.size();
            if(n==1)
            {
                return 0;
            }
            int lm = v[0];
            int ans = 0;
            //Max of the (current value-min value of stock till then) and current answer
            for(int i=1;i<n;i++)
            {
                ans = max(ans,v[i]-lm);
                lm = min(lm,v[i]);
            }
            return ans;
        }
};

class Solution
{
    public:
        int maxProfit(vector<int>& v)
        {
            int n = v.size();
            int ans = 0;
            int currMin = v[0];
            for(int i=1;i<n;i++)
            {
                currMin = min(v[i],currMin);
                ans = max(ans,v[i]-currMin);
            }
            return ans;
        }
};

