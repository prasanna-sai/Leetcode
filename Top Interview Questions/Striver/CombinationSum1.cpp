class Solution {
public:
    void helper(vector<int>& v,vector<vector<int>> &ans,vector<int> &curr,int in,int t, int &n)
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
        for(int i=in;i<n;i++)
        {
            if(v[i]<=t)
            {
                curr.push_back(v[i]);
                helper(v,ans,curr,i,t-v[i],n);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& v, int t)
    {
        int n = v.size();
        vector<vector<int>>ans;
        vector<int>curr;
        helper(v,ans,curr,0,t,n);
        return ans;
    }
};