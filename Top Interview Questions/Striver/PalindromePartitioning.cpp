class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        int n = s.length();
        vector<vector<string>>ans;
        vector<string>curr;
        helper(s, ans, curr, 0, n);
        return ans; 
    }

    void helper(string& s, vector<vector<string>>&ans, vector<string>& curr, int start, int n)
    {
        if(start==n)
        {
            ans.push_back(curr);
            return;
        }
        for(int i=start; i<n; i++)
        {
            if(isPalindrome(s, start, i))
            {
                curr.push_back(s.substr(start,i-start+1));
                helper(s, ans, curr, i+1, n);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end)
    {
        while(start <= end)
        {
            if(s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }
};