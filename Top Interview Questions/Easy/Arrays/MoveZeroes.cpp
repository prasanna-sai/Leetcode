class Solution
{
    public:
        void moveZeroes(vector<int>& nums)
        {
            int n = nums.size();
            int j = 0;
            //Maintain an index j for finding the numbers which are not zero, whenever we find that numbers,
            //move the values to the front, after that is done change values of remaining elements to zero.
            for(int i=0;i<n;i++)
            {
                if(nums[i]!=0)
                {
                    nums[j] = nums[i];
                    j++;
                }
            }
            for(int i=j;i<n;i++)
            {
                nums[i] = 0;
            }
        }
};
