//This is the old approach
class Solution
{
    public:
        vector<int> topKFrequent(vector<int>& v, int k)
        {
            sort(v.begin(),v.end());
            vector<pair<int,int>>ans;
            int n = v.size();
            int count = 1;
            for(int i=1;i<n;i++)
            {
                if(v[i] != v[i-1])
                {
                    ans.push_back({count,v[i-1]});
                    count = 1;
                    continue;
                }
                count++;
            }
            ans.push_back({count,v[n-1]});
            sort(ans.begin(),ans.end());
            vector<int>res;
            int sz = ans.size();
            for(int i=0;i<k;i++)
            {
                res.push_back(ans[sz-1-i].second);
            }
            return res;
        }
};

//This one is another approach that make use of priority queue

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