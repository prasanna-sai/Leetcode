class Solution
{
    public:
        bool isPowerOfThree(int n)
        {
            //Simple divide by three and check reminder approach
            while(n%3 == 0 && n>1)
            {
                n = n/3;
            }
            if(n==1)
            {
                return true;
            }
            return false;
        }
};