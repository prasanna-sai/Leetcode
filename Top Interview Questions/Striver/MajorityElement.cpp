class Solution {
public:
    int majorityElement(vector<int>& v)
    {
        int n = v.size();
        int ans = v[0];
        int count = 1;
        for(int i=1;i<n;i++)
        {
            if(count == 0)
            {
                ans = v[i];
            }
            count += ((v[i] == ans) ? 1 : -1);
        }
        return ans;
    }
};

class Solution {
    public:
        int majorityElement(vector<int>& v)
        {
            int n = v.size();
            int cnd = -1;
            int cnt = 0;
            for(int i: nums)
            {
                if(i == cnd)
                {
                    cnt++;
                }
                else if(cnt == 0)
                {
                    cnd = i;
                    cnt++;
                }
                else
                {
                    cnt--;
                }
            }
            return cnd;
        }
};