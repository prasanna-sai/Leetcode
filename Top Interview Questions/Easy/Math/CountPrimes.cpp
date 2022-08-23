class Solution
{
    public:
        int countPrimes(int n)
        {
            vector<bool> prime(n + 1, 1);
            prime[0] = prime[1] = 0;
            //sieve of eratosthenes technique
            for(int i = 2; i <= sqrt(n); i++)
            {
                if(prime[i])
                {
                    for(int j = i * i; j <= n; j += i)
                    {
                        prime[j] = 0;
                    }
                }
            }
            int ans = 0;
            for(int i = 2; i < n; i++)
            {
                if(prime[i])
                {
                    ans++;
                }
            }
            return ans;
        }
};