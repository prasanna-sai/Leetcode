class Solution
{
    public:
        vector<int> topKFrequent(vector<int>& nums, int k)
        {
            //Store the count of each element in the nums array in an unordered_map
            int n = nums.size();
            unordered_map<int, int>um;
            for(int i=0;i<n;i++)
            {
                if(um.find(nums[i]) == um.end())
                {
                    um.insert({nums[i],1});
                }
                else
                {
                    um[nums[i]]++;
                }
            }
            //Use Priority Queue as it is easier to get elements with some priority as we are dealing with priority here
            priority_queue<pair<int,int>> p;
            for(auto& x:um)
            {
                p.push({x.second,x.first});
            }
            vector<int>ans;
            for(int i=0;i<k;i++)
            {
                ans.push_back(p.top().second);
                p.pop();
            }
            return ans;
        }
};