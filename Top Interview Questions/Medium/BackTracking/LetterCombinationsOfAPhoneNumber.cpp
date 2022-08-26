    class Solution
    {
        vector<string>v{"00","11","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        public:
            vector<string> letterCombinations(string s)
            {
                if(s.length() == 0)
                {
                    return {};
                }
                vector<string>ans;
                int l = s.length();
                string val = "";
                helper(ans,s,val,0);
                return ans;
            }

            //This helper function acts like a backtracking function, len stores the current length of the newly created string
            //If it matches the required length, then we push that to the answer
            void helper(vector<string>& ans, string& s, string& perm, int len)
            {
                if(len == s.length())
                {
                    ans.push_back(perm);
                    return;
                }
                string s1 = v[(int)s[len] - 48];
                int l = s1.length();
                for(int i=0;i<l;i++)
                {
                    string aps = perm+s1[i];
                    helper(ans, s, aps, len+1);
                }
                return;
            }
    };


//Below is the iterative approach to the same
vector<string> letterCombinations(string digits)
{
    vector<string> res;
    string charmap[10] = {"00", "11", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    res.push_back("");
    for (int i = 0; i < digits.size(); i++)
    {
        vector<string> tempres;
        string chars = charmap[digits[i] - '0'];
        for (int c = 0; c < chars.size();c++)
            for (int j = 0; j < res.size();j++)
                tempres.push_back(res[j]+chars[c]);
        res = tempres;
    }
    return res;
}