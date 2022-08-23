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