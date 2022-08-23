class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        //XOR of a number with itself results in 0 and XOR of a number with 0 results in itself.
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans ^= nums[i];
        }
        return ans;
    }
};