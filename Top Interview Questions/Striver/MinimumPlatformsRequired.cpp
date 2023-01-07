class Solution
{
    public:

    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back(make_pair(arr[i],dep[i]));
        }
        sort(v.begin(),v.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        int ans = 1;
        pq.push(v[0].second);
        for (int i = 1; i < n; i++)
        {
            if (pq.top() >= v[i].first)
            {
                ans++;
            }
            else
            {
                pq.pop();
            }
            pq.push(v[i].second);
        }
        return ans;
    }
};