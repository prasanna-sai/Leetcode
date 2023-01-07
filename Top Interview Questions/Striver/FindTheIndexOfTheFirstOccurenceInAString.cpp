class Solution
{
    public:
        int strStr(string haystack, string needle)
        {
            if(needle == "")
            {
                return 0;
            }
            int n = haystack.length();
            int m = needle.length();
            //Check at each index, brute force algoritm
            //There is other variant called KMP algorithm, google it
            for(int i=0;i<n-m+1;i++)
            {
                int flag = 0;
                for(int j=i;j<i+m;j++)
                {
                    if(haystack[j] != needle[j-i])
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    return i;
                }
            }
            return -1;
        }
};

//Z Array solution
class Solution {
public:
    int strStr(string s, string f)
    {
        string x = f + "$" + s;
        int m = f.length();
        int n = x.length();
        vector<int>Z(n,0);
        getZArray(x,n,Z);
        for(int i=0;i<n;i++)
        {
            if(Z[i] == m)
            {
                return i-m-1;
            }
        }
        return -1;
    }

    void getZArray(string& s, int& n, vector<int>& Z)
    {
        int L=0,R=0;

        for(int i=1;i<n;i++)
        {
            if(i>R)
            {
                L = R = i;
                while(R<n && s[R-L] == s[R])
                {
                    R++;
                }
                Z[i] = R-L;
                R--;
            }
            else
            {
                int k = i-L;
                if(Z[k] < R-i+1)
                {
                    Z[i] = Z[k];
                }
                else
                {
                    L = i;
                    while(R<n && s[R-L] == s[R])
                    {
                        R++;
                    }
                    Z[i] = R-L;
                    R--;
                }
            }
        }
    }

};