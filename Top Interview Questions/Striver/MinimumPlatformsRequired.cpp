class Solution
{
	public:

	int findPlatform(int a[], int d[], int n)
	{
		vector<pair<int,int>>v;
		priority_queue<int, vector<int>, greater<int>>pq;
		for(int i=0;i<n;i++)
		{
			v.push_back({a[i], d[i]});
		}
		sort(v.begin(), v.end());
		int ans = 1;
		pq.push(v[0].second);
		for(int i=1; i<n; i++)
		{
			if(pq.top() >= v[i].first)
			{
				ans ++;
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


class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int a[], int d[], int n)
	{
		sort(a,a+n);
        sort(d, d+n);
        int ans = 1, i=1, j=0, curr = 1;
        while(i<n && j<n)
        {
            if(a[i] > d[j])
            {
                curr--;
                j++;
            }
            else
            {
                curr++;
                i++;
            }
            ans = max(ans, curr);
        }
        return ans;
	}
};