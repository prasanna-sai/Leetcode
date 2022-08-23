class Solution {
public:
    int maxProfit(vector<int>& v)
    {
        int n = v.size();
        int ans = 0;
        //If we find an element which is smaller then the next element,
        //we buy stock on that day and sell the stock on next day
        for(int i=0;i<n-1;i++)
        {
            if(v[i] < v[i+1])
            {
                ans = ans + v[i+1] - v[i];
            }
        }
        return ans;
    }
};