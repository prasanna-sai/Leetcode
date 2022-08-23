class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        //Since it is rotation by k times, the last k elements comes to first,
        //the other n-k elements go to last. Now reverse entire array, and separately reverse the first k
        //elements and last n-k elements to preserve the order
        k %=nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
