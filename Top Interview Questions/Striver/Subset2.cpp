class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& v)
    {
		int n = v.size();
		vector<vector<int>>ans;
		sort(v.begin(), v.end());
		vector<int>curr;
		helper(v, ans, curr, 0, n);
        return ans;
    }

	void helper(vector<int>&v, vector<vector<int>>&ans, vector<int>&curr, int index, int n)
	{
		ans.push_back(curr);
		for(int i=index;i<n;i++)
		{
			if(i != index && v[i] == v[i-1])
			{
				continue;
			}
			curr.push_back(v[i]);
			helper(v, ans, curr, i+1, n);
			curr.pop_back();
		}
	}
};