class Solution
{
    public:
    //Algorithm based on the comparison between target, last element of the array and the current middle element of the sub array
        int search(vector<int>& v, int target)
        {
            int n = v.size();
            if(n==0)
            {
                return -1;
            }
            if(v[n-1] == target)
            {
                return n-1;
            }
            int l = 0, r = n-1;
            bool var = (target<v[n-1]);
            while(l<r)
            {
                int m = l + (r-l)/2;
                if(var)
                {
                    if(v[m]<target || v[mid]>v[n-1])
                    {
                        l = mid+1;
                    }
                    else
                    {
                        r = mid;
                    }
                }
                else
                {
                    if(v[m]<target && v[mid]>v[n-1])
                    {
                        l = m + 1;
                    }
                    else
                    {
                        r = m;
                    }
                }
            }
            if(nums[l] == target)
            {
                return l;
            }
            return -1;
        }
};