class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int ans = 0;
        int n = nums.size();
        //Classic XOR technique 
        //XOR all the indices and the array values and the answer is the missing number
        for(int i=0;i<n;i++)
        {
            ans = ans ^ i ^ nums[i];
        }
        ans = ans ^ n;
        return ans;
    }
};