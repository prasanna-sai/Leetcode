class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        //Store elements in unordered set, if it happens that the element that is to be
        //inserted already exists, it means it has duplicate elements
        int n = nums.size();
        unordered_set<int> us;
        for(int i=0;i<n;i++)
        {
            if(us.find(nums[i]) == us.end())
            {
                us.insert(nums[i]);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};