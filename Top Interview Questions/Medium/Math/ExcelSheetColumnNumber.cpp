class Solution {
public:
    int titleToNumber(string s)
    {
        int ans = 0;
        int l = s.length();
        for(int i=0;i<l;i++)
        {
            ans = ans*26 + ((int)s[i] - 64);
        }
        return ans;
    }
};
