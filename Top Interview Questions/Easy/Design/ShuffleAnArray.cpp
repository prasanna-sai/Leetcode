class Solution
{
    private:
    vector<int> org;
    public:
        Solution(vector<int>& nums)
        {
            org = nums;
        }

        vector<int> reset()
        {
            return org;
        }

        vector<int> shuffle()
        {
            vector<int> temp = org;
            for(int i = temp.size(); i > 0; --i)
            {
                swap(temp[rand()%i], temp[i-1]); // swap with last element from this iteration with a random element from the domain
            }
            return temp;
        }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */