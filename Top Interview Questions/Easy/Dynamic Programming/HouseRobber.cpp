class Solution
{
    public:
        int rob(vector<int>& v)
        {
            int n = v.size();
            if(n==1)
            {
                return v[0];
            }
            if(n==2)
            {
                return max(v[0],v[1]);
            }
            int x = v[0];
            int y = max(v[0],v[1]);
            int ans = 0;
            //Max of upto previous house and (current house + previous's previous house)
            for(int i=2;i<n;i++)
            {
                ans = max(y,x+v[i]);
                x = y;
                y = ans;
            }
            return ans;
        }
};