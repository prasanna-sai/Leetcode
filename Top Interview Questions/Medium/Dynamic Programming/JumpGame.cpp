class Solution {
    public:
        bool canJump(vector<int>& v)
        {
            //we use reach variable to store the maximum reachable index until now
            //If the reach variable is less than the current index, that means we can't reach the end
            int n = v.size();
            int reach = 0;
            for(int i=0;i<n;i++)
            {
                if(i <= reach)
                {
                    reach = max(reach,i+v[i]);
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
};