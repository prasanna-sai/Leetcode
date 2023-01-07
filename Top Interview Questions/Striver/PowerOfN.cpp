class Solution
{
    public:
        double myPow(double x, int N)
        {
            double ans = 1.0;
            long long int n = N;
            if (N < 0)
            {
                x = 1/x;
                n = abs(n);
            }
            long long int i = 1;
            while(i <= n)
            {
                ans = ans * x;
                if(i*2 <= n)
                {
                    ans = ans * ans;
                    i = i*2;
                }
                i++;
            }
            return ans;
        }
};