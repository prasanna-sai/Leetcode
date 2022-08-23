class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if(n <= 1)
        {
            return s;
        }
        int index = 0;
        int len = 0;
        for(int i=0;i<n;i++)
        {
            cout<<s[i]<<endl;
            int x=i,y=i;
            //Next two loops are for removing duplicate characters
            for(int j=i-1;j>=0;j--)
            {
                if(s[i]==s[j])
                {
                    x--;
                }
                else
                {
                    break;
                }
            }
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    y++;
                }
                else
                {
                    break;
                }
            }
            i = y;
            while(x>=0 && y<n)
            {
                if(s[x] != s[y])
                {
                    break;
                }
                x--;
                y++;
            }
            x = x+1;
            y = y-1;
            int z = y-x+1;
            if(z>len)
            {
                len = z;
                index = x;
            }
        }
        return s.substr(index, len);
    }
};