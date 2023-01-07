class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        for(auto x : g)
        {
            pq1.push(x);
        }
        for(auto x : s)
        {
            pq2.push(x);
        }
        int ans = 0;
        while(!pq2.empty() && !pq1.empty())
        {
            if(pq2.top() >= pq1.top())
            {
                ans++;
                pq1.pop();
            }
            pq2.pop();
        }
        return ans;
    }
};