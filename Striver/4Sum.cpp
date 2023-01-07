class Solution
{
    public:
        vector<vector<int>> fourSum(vector<int>& v, int target)
        {
            int n = v.size();
            vector<vector<int>>ans;
            set<vector<int>>s;
            if(n<4)
            {
                return ans;
            }
            sort(v.begin(),v.end());
            for(int i=0;i<n-3;i++)
            {
                for(int j=i+1;j<n-2;j++)
                {
                    int l = j+1;
                    int r = n-1;
                    while(l<r)
                    {
                        long long sum = (long long)v[i]+ (long long)v[j]+(long long)v[l]+(long long)v[r];
                        if(sum == target)
                        {
                            s.insert({v[i],v[j],v[l],v[r]});
                        }
                        if(sum<target)
                        {
                            l++;
                            continue;
                        }
                        r--;
                    }
                }
            }
            for(auto i : s)
            {
                ans.push_back(i);
            }
            return ans;
        }
};