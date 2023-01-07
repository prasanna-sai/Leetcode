class Solution {
public:
    int majorityElement(vector<int>& v) {
        int n = v.size();
        int ans = -1;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(count == 0)
            {
                ans = v[i];
            }
            count += (ans == v[i]) ? 1 : -1;
        }
        return ans;
    }
};

