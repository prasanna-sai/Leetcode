class Solution
{
    public:
        vector<vector<int>> fourSum(vector<int>& v, int target)
        {
            int n = v.size();
            vector<vector<int>>ans;
            set<vector<int>>s;
            sort(v.begin(), v.end());
            if(n<4)
            {
                return ans;
            }
            for(int i=0;i<n-3;i++)
            {
                for(int j=i+1;j<n-2;j++)
                {
                    int l = j+1;
                    int r = n-1;
                    long long int rem = (long long int)target - v[i] - v[j];
                    while(l<r)
                    {
                        long long int x = v[l] + v[r];
                        if( x == rem)
                        {
                            s.insert({v[i],v[j],v[l],v[r]});
                            l++;
                            r--;
                        }
                        else if(x < rem)
                        {
                            l++;
                        }
                        else
                        {
                            r--;
                        }
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