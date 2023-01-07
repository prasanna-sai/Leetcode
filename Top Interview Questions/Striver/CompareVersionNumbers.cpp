class Solution
{
    public:
        int compareVersion(string s1, string s2)
        {
            int m = s1.length(), n = s2.length();
            int i=0,j=0;
            while(i<m || j<n)
            {
                int v1=0, v2 = 0;
                while(i<m && s1[i] != '.')
                {
                    v1 = v1*10 + (s1[i]-'0');
                    i++;
                }
                while(j<n && s2[j] != '.')
                {
                    v2 = v2*10 + (s2[j]-'0');
                    j++;
                }
                if(v1>v2)
                {
                    return 1;
                }
                else if(v1<v2)
                {
                    return -1;
                }
                i++;
                j++;
            }
            return 0;
        }
};