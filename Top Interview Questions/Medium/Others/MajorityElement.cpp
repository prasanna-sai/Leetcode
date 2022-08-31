class Solution {
public:
    int majorityElement(vector<int>& v)
    {
        //Store frequency of each element in unordered map and returns the element value if
        //frequency exceeds n/2
        unordered_map<int,int>um;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            if(um.count(v[i]) == 0)
            {
                um.insert({v[i],1});
            }
            else
            {
                um[v[i]] += 1;
            }
            if(um[v[i]] > n/2)
            {
                return v[i];
            }
        }
        return 0;
    }
};