class Solution {
public:
    int singleNonDuplicate(vector<int>& v)
    {
        int ans = 0;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            ans = ans ^ v[i];
        }
        return ans;
    }
};


class Solution {
public:
    int singleNonDuplicate(vector<int>& v)
    {
        int n = v.size();
        if(n==1 || v[0] != v[1])
        {
            return v[0];
        }
        if(v[n-1] != v[n-2])
        {
            return v[n-1];
        }
        int low = 1, high = n-2;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(v[mid] != v[mid+1] && v[mid] != v[mid-1])
            {
                return v[mid];
            }
            if((mid%2 == 0 && v[mid] == v[mid+1]) || (mid%2 == 1 && v[mid] == v[mid-1]))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};