class Solution {
public:
    bool increasingTriplet(vector<int>& v)
    {
        int n = v.size();
        int x = INT_MAX;
        int y = INT_MAX;
        //x and y to store two elements that are lesser than the current one if exists
        for(int i=0;i<n;i++)
        {
            if(v[i]<x)
            {
                x = v[i];
            }
            else if(v[i]>x && v[i]<y)
            {
                y = v[i];
            }
            else if(v[i]>y)
            {
                return true;
            }
        }
        return false;
    }
};