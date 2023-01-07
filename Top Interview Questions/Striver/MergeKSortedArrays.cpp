vector<int> mergeKSortedArrays(vector<vector<int>>&v, int k)
{
    vector<int>ans;
    priority_queue<int, greater<int>>pq;
    for(int i=0;i<k;i++)
    {
        int l = v[i].size();
        for(int j=0;j<l;j++)
        {
            pq.push(v[i][j]);
        }
    }
    while(!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
