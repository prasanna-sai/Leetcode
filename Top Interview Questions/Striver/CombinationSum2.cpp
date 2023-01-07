class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& v, int t)
    {
        int n = v.size();
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        vector<int>curr;
        helper(v,ans,curr,0,t,n);
        return ans;
    }
    void helper(vector<int>&v, vector<vector<int>>&ans, vector<int>&curr, int index, int t, int& n)
    {
        if(t==0)
        {
            ans.push_back(curr);
            return;
        }
        if(t<0)
        {
            return;
        }
        for(int i = index;i<n;i++)
        {
            if(i!=index && v[i] == v[i-1])
            {
                continue;
            }
            if(v[i]<=t)
            {
                curr.push_back(v[i]);
                helper(v,ans,curr,i+1,t-v[i],n);
                curr.pop_back();
            }
            else
            {
                break;
            }
        }
    }
};