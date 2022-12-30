class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v)
    {
        int ans = 0;
        int curr = 0;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i] == 1)
            {
                curr++;
            }
            else
            {
                ans = max(ans,curr);
                curr = 0;
            }
        }
        ans = max(ans,curr);
        return ans;
    }
};