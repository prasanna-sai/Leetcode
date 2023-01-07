//Solution based on atleast one side of the array is sorted, and then element one side based on the check if element is there on the sorted side or not
class Solution{
public:
    int search(vector<int>& v, int target)
    {
        int n = v.size();
        int l = 0;
        int r = n-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(v[m] == target)
            {
                return m;
            }
            if(v[l] <= v[m])
            {
                if(v[l] <= target && v[m] >= target)
                {
                    r = m-1;
                }
                else
                {
                    l = m + 1;
                }
            }
            else
            {
                if(v[m] <= target && v[r] >= target)
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};