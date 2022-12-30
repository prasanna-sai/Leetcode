class Solution {
public:
    int trap(vector<int>& v)
    {
        int n = v.size();
        vector<int>lm(n,0),rm(n,0);
        int x = v[0];
        for(int i=1;i<n-1;i++)
        {
            x =  max(x,v[i-1]);
            lm[i] = x;
        }
        x = v[n-1];
        for(int i=n-2;i>0;i--)
        {
            x = max(x,v[i]);
            rm[i] = x;
        }
        int ans = 0;
        for(int i=1;i<n-1;i++)
        {
            ans = ans + max(0,min(lm[i],rm[i])-v[i]);
        }
        return ans;
    }
};