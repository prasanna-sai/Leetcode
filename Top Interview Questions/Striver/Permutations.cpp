class Solution {
public:
    vector<vector<int>> permute(vector<int>& v)
    {
        vector<vector<int>>ans;
        int n = v.size();
        helper(ans,v,0);
        return ans;
    }

    //Helper function to swap elements at each index and backtrack
    void helper(vector<vector<int>>& ans, vector<int>& v, int i)
    {
        if(i == v.size())
        {
            ans.push_back(v);
            return;
        }
        for(int k=i;k<v.size();k++)
        {
            swap(v[i],v[k]);
            helper(ans,v,i+1);
            swap(v[i],v[k]); //backtracking to original after recursion is called.
        }
        return;
    }
};