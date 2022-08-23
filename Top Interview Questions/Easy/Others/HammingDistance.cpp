class Solution
{
    public:
        int hammingDistance(int x, int y)
        {
            //DO XOR of two numbers the different bits get set to 1 and count the number of set bits
            int n = x ^ y;
            int count = 0; 
            while (n)
            { 
                count += n & 1; 
                n >>= 1; 
            } 
            return count;
        }
};