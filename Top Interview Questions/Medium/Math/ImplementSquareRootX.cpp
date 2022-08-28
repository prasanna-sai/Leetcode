class Solution
{
    public:
    //We are using the sorted property of the integers and use the binary search to get the correct number
        int mySqrt(int x)
        {
            if (x < 2) return x;
            unsigned int left = 0, right = x;
            
            while (left < right) {
                
                unsigned long int mid = (right + left) / 2;
                
                unsigned long long res = mid * mid;

                if (res <= x && pow((mid + 1), 2) > x) {
                    return mid;
                }
                else if (res < x) {
                    left = mid + 1;
                }
                else if (res > x) {
                    right = mid;
                }
            }
            return 0;
        }
};