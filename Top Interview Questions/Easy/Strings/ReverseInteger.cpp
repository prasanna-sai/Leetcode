class Solution {
public:
    int reverse(int x) 
    {
        //Find the integer negative or positive for final answer.
        int flag = 1;
        if(x<0)
        {
            flag = -1;
            x = abs(x);
        }
        int ans = 0;
        while(x>0)
        {
            if(ans > INT_MAX/10) //Check to avoid overflow of the integer
            {
                return 0;
            }
            ans = ans*10 + (x%10);
            x = x/10;
        }
        return flag*ans;
    }
};