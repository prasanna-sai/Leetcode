class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string>ans;
        helper(ans,2*n,0,0,"");
        return ans;
    }
    //Helper function that helps us in decide what to insert to the string based on the current length
    //of the string, and no of left braces and right braces at that moment.
    //here backtracking is we terminate the function call if the string is invalid.
    void helper(vector<string>& ans, int n, int lc, int rc, string s)
    {
        if(s.length() == n)
        {
            ans.push_back(s);
            return;
        }
        if(lc<rc)
        {
            return;
        }
        if(lc<n/2)
        {
            if(lc == rc)
            {
                s = s + "(";
                helper(ans,n,lc+1,rc,s);
                return;
            }
            else if(lc>rc)
            {
                helper(ans,n,lc+1,rc,s+"(");
                helper(ans,n,lc,rc+1,s+")");
                return;
            }
            else
            {
                return;
            }
        }
        if(lc==n/2)
        {
            helper(ans,n,lc,rc+1,s+")");
            return;
        }
    }
};