class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& v)
    {
        int n = v.size();
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        vector<int>curr;
        helper(v,ans,0,n,curr);
        return ans;
    }
    void helper(vector<int>&v, vector<vector<int>>&ans, int index, int& n, vector<int>&curr)
    {
        ans.push_back(curr);
        for(int i = index;i<n;i++)
        {
            if(i!=index && v[i] == v[i-1])
            {
                continue;
            }
            curr.push_back(v[i]);
            helper(v,ans,i+1,n,curr);
            curr.pop_back();
        }
    }
};