class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.size() == 0)
            return 0;
        
        int i = 0; // index of the current element
        int j = 0; // index of the next element
        while (j < nums.size()) // while there are still elements to compare
        {
            if (nums[i] != nums[j]) // if the current element is not the same as the next element
            {
                i++; // increment the index of the current element
                nums[i] = nums[j]; // assign the next element to the current element
            }
            j++; // increment the index of the next element
        }
        return i + 1;
    }
};