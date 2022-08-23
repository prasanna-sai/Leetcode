class Solution
{
    public:
        bool isPalindrome(string s)
        {
            //Add the alphanumeric values to a new string and check if the resultant string is palindrome or not
            int l = s.length();
            string ans = "";
            for(int i=0;i<l;i++)
            {
                if(((int)s[i]>=48 && (int)s[i]<=57) || ((int)s[i]>=97 && (int)s[i]<=122))
                {
                    ans += s[i];
                }
                else if(((int)s[i]>=65 && (int)s[i]<=90)) //Convert capitals to smallcase
                {
                    ans += (char)((int)s[i] + 32);
                }
            }
            l = ans.length();
            for(int i=0;i<l/2;i++)
            {
                if(ans[i]!=ans[l-i-1])
                {
                    return false;
                }
            }
            return true;
        }
};