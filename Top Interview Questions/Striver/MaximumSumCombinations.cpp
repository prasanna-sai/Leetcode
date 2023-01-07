vector<int> Solution::solve(vector<int> &v1, vector<int> &v2, int C)
{
    int n = v1.size();
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    priority_queue<pair<int, pair<int,int>>>pq;
    pq.push({v1[n-1]+v2[n-1], {n-1, n-1}});
    set<pair<int,int>>s;
    s.insert({n-1,n-1});
    vector<int>ans;
    while(C>0)
    {
        pair<int, pair<int,int>>p = pq.top();
        pq.pop();
        ans.push_back(p.first);
        int x = p.second.first, y = p.second.second;
        if(s.count({x-1,y}) == 0)
        {
            pq.push({v1[x-1]+v2[y],{x-1,y}});
            s.insert({x-1,y});
        }
        if(s.count({x,y-1}) == 0)
        {
            pq.push({v1[x]+v2[y-1],{x,y-1}});
            s.insert({x,y-1});
        }
        C--;
    }
    return ans;
}