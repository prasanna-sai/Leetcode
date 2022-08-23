class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v)
    {
        sort(v.begin(),v.end()); //Sort the array
        int n = v.size();
        unordered_map<int,int>um;
        //Store the values and the indices in unordered map, incase of duplicates store the last index.
        for(int i=0;i<n;i++)
        {
            um[v[i]] = i;
        }
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++)
        {
            if(v[i]>0) //If the first number is positive, no point in finding the other elements as the others will be postive
            {
                break;
            }
            for(int j=i+1;j<n-1;j++)
            {
                int val = -1*(v[i]+v[j]); //The third value we need
                if(um.find(val) != um.end() && um[val]>j) //Find in unordered map
                {
                    ans.push_back({v[i],v[j],val});
                }
                j = um[v[j]]; //To avoid duplicates and speed up the algo
            }
            i = um[v[i]]; //To avoid duplicates and speed up the algo
        }
        return ans;
    }
};