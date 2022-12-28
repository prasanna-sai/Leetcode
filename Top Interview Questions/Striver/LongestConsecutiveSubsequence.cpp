class Solution
{
    public:
        int longestConsecutive(vector<int>& v)
        {
            unordered_set<int>us;
            for(auto& i:v)
            {
                us.insert(i);
            }
            int ans = 0;
            for(auto it=us.begin();it!=us.end();it++)
            {
                int val = *it;
                int curr = 1;
                if(us.find(val-1) == us.end())
                {
                    val = val + 1;
                    while(us.find(val) != us.end())
                    {
                        curr++;
                        val++;
                    }
                    ans = max(ans,curr);
                }
            }
            return ans;
        }
};