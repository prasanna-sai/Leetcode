class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        //Insert elements into the unordered map, find if the target-current_element
        //exists and then return those two indices.
        int n = nums.size();
        unordered_map<int,int>um;
        for(int i=0;i<n;i++)
        {
            um.insert({nums[i],i});
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int val = target - nums[i];
            if(um.find(val) != um.end() && um[val]!=i)
            {
                ans.push_back(i);
                ans.push_back(um[val]);
                return ans;
            }
        }
        return ans;
    }
};