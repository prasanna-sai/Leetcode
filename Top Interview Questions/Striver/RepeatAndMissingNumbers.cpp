class Solution {
public:
    int findDuplicate(vector<int>& v)
    {
        int n = v.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int idx = abs(v[i]);
            if(v[idx]<0)
            {
                return idx;
            }
            v[idx] *= -1;
        }
        return 0;
    }
};