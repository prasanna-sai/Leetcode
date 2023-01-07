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

    void helper(vector<int>& v, vector<vector<int>>& ans, vector<int> curr, int index, int n)
    {
        if(index == n)
        {
            ans.push_back(curr);
            return;
        }
        int newIndex = index;
        for(int i=index;i<n;i++)
        {
            if(v[i] != v[index])
            {
                newIndex = i;
                break;
            }
            else
            {
                newIndex = n;
            }
        }
        helper(v, ans, curr, newIndex, n);
        curr.push_back(v[index]);
        helper(v, ans, curr, index+1, n);
    }
};