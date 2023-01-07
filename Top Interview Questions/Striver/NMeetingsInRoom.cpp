class Solution
{
    public:

    bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
    {
        return (a.second < b.second);
    }

    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back(make_pair(start[i],end[i]));
        }
        sort(v.begin(),v.end(),sortbysec);
        int ans = 1;
        int val = v[0].second;
        for(int i=1;i<n;i++)
        {
            if(v[i].first > val)
            {
                ans++;
                val = v[i].second;
            }
        }
        return ans;
    }
};