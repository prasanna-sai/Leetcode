class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>>ans;
        vector<int>curr;
        helper(ans,nums,curr,0);
        return ans;
    }
    //Add each element
    void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int i)
    {
        ans.push_back(curr);
        for(int k=i;k<nums.size();k++)
        {
            curr.push_back(nums[k]);
            helper(ans,nums,curr,k+1);
            curr.pop_back(); //Backtracking step
        }
        return;
    }
};