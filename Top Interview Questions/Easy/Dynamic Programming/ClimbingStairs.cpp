class Solution {
public:
    int climbStairs(int n)
    {
        int x = 1;
        int y = 1;
        if(n==1)
        {
            return 1;
        }
        int ans = 0;
        //Number of ways to reach the Nth stair is sum of no of ways to reach the (N-1) stair and (N-2) stair
        for(int i=2;i<=n;i++)
        {
            ans = x + y;
            x = y;
            y = ans;
            
        }
        return ans;
    }
};