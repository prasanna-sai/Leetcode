class Solution {
public:
    bool isValid(string s)
    {
        int l = s.length();
        stack<char>st;
        for(int i=0;i<l;i++)
        {
            if(s[i] == '{' || s[i] == '(' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else if (st.empty() || (s[i]=='}' && st.top() != '{') || (s[i]==')' && st.top() != '(' ) || (s[i]==']' && st.top() != '['))
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
        return st.empty();   
    }
};