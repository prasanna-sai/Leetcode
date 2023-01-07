class Solution
{
    public:
        int maxSubArray(vector<int>& v)
        {
            int n = v.size();
            int ans = INT_MIN;
            int cur = 0;
            //We will add the current index value to the curr and update curr to 0 if it is negative.
            //Ans is max of curr and previous max
            for(int i=0;i<n;i++)
            {
                cur += v[i];
                ans = max(ans,cur);
                cur = max(cur,0);
            }
            return ans;
        }
};

class Solution
{
    public:
        int maxSubArray(vector<int>& v)
        {
            int n = v.size();
            int ans = v[0];
            int currSum = v[0];
            for(int i=1;i<n;i++)
            {
                currSum = max(currSum,0);
                currSum += v[i];
                ans = max(ans, currSum);
            }
            return ans;
        }
};