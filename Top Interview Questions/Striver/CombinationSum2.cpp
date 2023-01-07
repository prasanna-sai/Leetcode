class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& v, int target)
    {
        vector<vector<int>>ans;
        vector<int>curr;
        int currSum = 0;
        int n = v.size();
        sort(v.begin(), v.end());
        helper(ans, curr, v, 0, n, target, 0);
        return ans;
    }

    void helper(vector<vector<int>>&ans, vector<int>&curr, vector<int>v, int index, int n, int target, int currSum)
    {
        if(currSum == target)
        {
            ans.push_back(curr);
        }
        if(currSum > target)
        {
            return;
        }
        for(int i=index; i<n; i++)
        {
            if(i!= index && v[i] == v[i-1])
            {
                continue;
            }
            if(v[i]+currSum <= target)
            {
                curr.push_back(v[i]);
                helper(ans, curr, v, i+1, n, target, currSum+v[i]);
                curr.pop_back();
            }
            else
            {
                break;
            }
        }
    }
};