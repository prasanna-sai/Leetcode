class Solution {
public:
    bool isValid(string s)
    {
        int l = s.length();
        stack<char>st;
        for(int i=0;i<l;i++)
        {
            //Push into stack when the bracket is the left ones
            if(s[i] == '{' || s[i] == '(' || s[i] == '[')
            {
                st.push(s[i]);
                continue;
            }
            if(st.empty())
            {
                return false;
            }
            //If the brancket is right one, Pop based on the condition whethet the top one matches with the same type left bracket
            if((st.top() == '{' && s[i]=='}') || (st.top() == '(' && s[i]==')') || (st.top() == '[' && s[i]==']'))
            {
                st.pop();
                continue;
            }
            return false;
        }
        if(st.empty())
        {
            return true;
        }
        return false;    
        }
};