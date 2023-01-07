class Solution {
	public:
    	vector<int> subsetSums(vector<int> v, int n)
    	{
			vector<int>ans;
			helper(v, ans, 0, 0, n);
			return ans;
		}

		void helper(vector<int>&v, vector<int>&ans, int sum ,int i, int n)
		{
			if(index == n)
			{
				ans.push_back(sum);
				return;
			}
			helper(v, ans, sum + v[i], i+1, n);
			helper(v, ans, sum, i+1, n);
			return;
		}
};