class Solution
{
    public:
        double myPow(double x, int N) {
        
        long long n = N;
        double res = 1.0;
        if(n < 0)
        {
            x = 1/x;
            n = abs(n);
        } 
        long long i = 1;
        while(i <= n)
        {
            res = res*x;
            if(i*2 < n)
            {
                res *= res;
                i = i*2 + 1;
            }
            else
            {
                i++;
            }
        }
        return res;
    }
};