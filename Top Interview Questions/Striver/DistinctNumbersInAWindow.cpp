vector<int> Solution::dNums(vector<int> &v, int B)
{
    vector<int>ans;
    unordered_map<int,int>um;
    int n = v.size();
    if(B>n)
    {
        return ans;
    }
    for(int i=0;i<B;i++)
    {
        um[v[i]]++;
    }
    ans.push_back(um.size());
    for(int i=1;i<=n-B;i++)
    {
        um[v[i-1]]--;
        if(um[v[i-1]] == 0)
        {
            um.erase(v[i-1]);
        }
        um[v[i+B-1]]++;
        ans.push_back(um.size());
    }
    return ans;
}
