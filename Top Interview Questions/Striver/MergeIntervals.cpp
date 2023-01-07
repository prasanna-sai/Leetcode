class Solution
{
    public:
        //Sort the vectors based on the start times and iterate and merge the intervals based on end time of previous interval
        //and start time of the next interval and push the interval to the answer
        vector<vector<int>> merge(vector<vector<int>>& v)
        {
            if(v.empty())
            {
                return {};
            }
            int n = v.size();
            sort(v.begin(),v.end());
            vector<vector<int>>ans;
            for(int i=1;i<n;i++)
            {
                if(v[i][0] <= v[i-1][1])
                {
                    v[i][0] = v[i-1][0];
                    v[i][1] = max(v[i][1] , v[i-1][1]);
                    continue;
                }
                ans.push_back({v[i-1][0] , v[i-1][1]});
            }
            ans.push_back({v[n-1][0] , v[n-1][1]});
            return ans;
        }
};