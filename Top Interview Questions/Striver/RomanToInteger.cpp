class Solution {
public:
    int romanToInt(string s)
    {
        int n=s.size();
        int res=0; 
        res=getInteger(s[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            //Value to be fetched based on the diffence of IX and XI example
            if(getInteger(s[i])>=getInteger(s[i+1]))
            {
                res+=getInteger(s[i]);
            }
            else
            {
                res-=getInteger(s[i]); 
            }
        }
        return res;
    }
    int getInteger(char c)
    {
        switch(c)
        {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return -1;
        } 
    }
};