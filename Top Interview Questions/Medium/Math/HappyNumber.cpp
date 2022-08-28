class Solution {
public:
    bool isHappy(int n)
    {
        unordered_set<int>us;
        while(n!=1)
        {
            if(us.count(n))
            {
                return false;
            }
            us.insert(n);
            int sum = 0;
            while(n)
            {
                sum = sum + pow(n%10,2);
                n = n/10;
            }
            n = sum;
        }
        return true;
    }
};