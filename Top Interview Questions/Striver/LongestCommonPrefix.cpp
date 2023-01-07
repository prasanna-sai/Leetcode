class Solution {
public:
    string longestCommonPrefix(vector<string>& s)
    {
        string ans="";
        int n=s.size();
        //Sort the strings in the array and find the common prefix in first and last element
        sort(s.begin(),s.end());
        for(int i=0;i<s[0].size();i++)
        {
            if(s[0][i]==s[n-1][i])
            {
                ans.push_back(s[0][i]);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& s)
    {
        string ans="";
        int n=s.size();
        for(int i=0;i<s[0].length();i++)
        {
            char c = s[0][i];
            for(int j=1;j<n;j++)
            {
                if(s[j].length() == i || s[j][i] != c)
                {
                    return s[0].substr(0,i);
                }
            }
        }
        return s[0];
    }
};