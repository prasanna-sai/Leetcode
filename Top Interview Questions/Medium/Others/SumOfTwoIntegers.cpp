class Solution {
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            int carry =  a & b; //calculate the carry
            a = a ^ b; //a stores the sum with out carry
            b = (unsigned int)carry << 1; //b stores the left shift of carry
        }
        return a;
    }
};