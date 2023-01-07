class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v)
    {
        int n = v.size();
        sort(v.begin(), v.end());
        unordered_map<int,int>um;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            um[v[i]] = i;
        }
        for(int i=0;i<n-2;i++)
        {
            if(v[i] > 0)
            {
                break;
            }
            for(int j=i+1;j<n-1;j++)
            {
                int val = -1*(v[i]+v[j]);
                if(um.count(val)>0 && um[val]>j)
                {
                    ans.push_back({v[i],v[j],val});
                }
                j = um[v[j]];
            }
            i = um[v[i]];
        }
        return ans;
    }
};