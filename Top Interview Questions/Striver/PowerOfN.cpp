class Solution
{
    public:
        double myPow(double x, int N)
        {
            double ans = 1.0;
            long long int pow = N;
            if (N < 0)
            {
                x = 1/x;
                pow = abs(pow);
            }
            while(pow)
            {
                if(pow % 2)
                {
                    ans = ans * x;
                    pow--;
                }
                else
                {
                    x = x * x;
                    pow/=2;
                }
            }
            return ans;
        }
};