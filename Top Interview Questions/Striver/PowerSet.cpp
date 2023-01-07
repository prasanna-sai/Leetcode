class Solution
{
	public:
		vector<string> AllPossibleStrings(string s)
        {
            vector<string>ans;
            string temp = "";
            helper(0, ans, s, temp);
            sort(ans.begin(), ans.end());
            return ans;
		}

        void helper(int index, vector<string>& ans, string& s, string& temp)
        {
            if(index == s.length())
            {
                if(temp != "")
                {
                    ans.push_back(temp);
                }
                return;
            }
            temp = temp + s[index];
            helper(index+1, ans, s, temp);
            temp.pop_back();
            helper(index+1, ans, s, temp);
        }
};

vector<string> AllPossibleStrings(string s) {
	int n = s.length();
	vector<string>ans;
	for (int num = 0; num < (1 << n); num++) {
		string sub = "";
		for (int i = 0; i < n; i++) {
			//check if the ith bit is set or not
			if (num & (1 << i)) {
				sub += s[i];
			}
		}
		if (sub.length() > 0) {
			ans.push_back(sub);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}
