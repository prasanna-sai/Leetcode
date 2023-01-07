class Solution {
public:
    int findDuplicate(vector<int>& v)
    {
        int n = v.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int idx = abs(v[i]);
            if(v[idx]<0)
            {
                return idx;
            }
            v[idx] *= -1;
        }
        return 0;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& v)
    {
        int slow = v[0], fast = v[0];
        do
        {
            slow = v[slow];
            fast = v[v[fast]];
        }
        while(fast != slow);
        fast = v[0];
        while(slow != fast)
        {
            slow = v[slow];
            fast = v[fast];
        }
        return slow;
    }
};