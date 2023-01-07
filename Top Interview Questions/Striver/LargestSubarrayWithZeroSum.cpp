class Solution
{
    public:
        int maxLen(vector<int>&v, int n)
        {   
            unordered_map<int,int>um;
            int sum = 0;
            int ans = 0;
            for(int i=0;i<n;i++)
            {
                sum += v[i];
                if(sum == 0)
                {
                    ans = i+1;
                    continue;
                }
                if(um.find(sum) != um.end())
                {
                    ans = max(ans,i-um[sum])
                }
                else
                {
                    um[sum] = i;
                }
            }
            return ans;
        }
};


class Solution {
	public:
    	int maxLen(vector<int>& v, int n)
    	{
			unordered_map<int, int> um;
			um[0] = -1;
			int ans = 0;
			int sum = 0;
			for(int i=0;i<n;i++)
			{
				sum += v[i];
				if(um.count(sum) > 0)
				{
					ans = max(ans, i-um[sum]);
				}
				else
				{
					um[sum] = i;
				}
			}
			return ans;
    	}
};