class Solution
{
    public:
        vector<int> plusOne(vector<int>& digits)
        {
            //Find the first index of the number which is not 9 from the end,
            //Now make all numbers(essentially all 9s) right of the index as 0,
            //if index is -1, which means we have to add 1 an the end, otherwise
            //Just increase the value in that index.
            int n = digits.size();
            int i;
            for(i=n-1;i>=0;i--)
            {
                if(digits[i] != 9)
                {
                    break;
                }
            }
            if(i == -1)
            {
                for(int j=0;j<n;j++)
                {
                    digits[j] = 0;
                }
                digits.insert(digits.begin(),1);
                return digits;
            }
            digits[i]++;
            for(int j=i+1;j<n;j++)
            {
                digits[j] = 0;
            }
            return digits;
        }
};
