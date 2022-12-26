class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();
        if(n==0)
        {
            return {-1,-1};
        }
        int l = 0;
        int r = n-1;
        //code for finding lower bound
        while(l<r)
        {
            int m = (l+r)/2;
            if(target<=nums[m])
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        if(nums[l] != target)
        {
            return{-1,-1};
        }
        int x = l;
        r = n-1;
        //code for finding upper bound
        while(x<r)
        {
            int m = ceil((x+r)/2.0);
            if(target < nums[m])
            {
                r = m-1;
            }
            else
            {
                x = m;
            }
        }
        return {l,r};
    }
};

//We can use simpler STL lower_bound and upper_bound too

class Solution
{
    public:
        vector<int> searchRange(vector<int>& v, int target)
        {
            if(v.size() == 0)
            {
                return {-1 , -1};
            }
            vector<int>::iterator l,u;
            l = lower_bound(v.begin(),v.end(),target);
            u = upper_bound(v.begin(),v.end(),target);
            return l!=v.end()&&*l==target?vector<int>{l-v.begin(),u-v.begin()-1}:vector<int>{-1,-1};
        }
};