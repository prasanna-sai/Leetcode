class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& v, int target)
    {
        vector<vector<int>>ans;
        vector<int>curr;
        int n = v.size();
        sort(v.begin(), v.end());
        helper(v, ans, curr, target, 0, 0, n);
        return ans;
    }

    void helper(vector<int>&v, vector<vector<int>>&ans, vector<int>curr, int target, int currSum, int index, int n)
    {
        if(currSum == target)
        {
            ans.push_back(curr);
            return;
        }
        if(currSum > target)
        {
            return;
        }
        for(int i=index; i<n; i++)
        {
            if(v[i] + currSum <= target)
            {
                curr.push_back(v[i]);
                helper(v,ans,curr,target,currSum+v[i],i,n);
                curr.pop_back();
            }
            else
            {
                break;
            }
        }

    }
};