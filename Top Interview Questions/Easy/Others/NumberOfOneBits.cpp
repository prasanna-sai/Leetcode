class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        //Do AND operation with 1 to check last bit's value and do the right shift operation on the number
        for (int i = 0; i < 32; ++i)
        {
            if (n & 1)
            {
                ++ans;
            }
            n = n >> 1;
        }
        return ans;   
    }
};