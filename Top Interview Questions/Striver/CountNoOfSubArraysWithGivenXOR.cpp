int Solution::solve(vector<int> &v, int m)
{
    int n = v.size();
    unordered_map<int,int>um;
    int ans = 0;
    int val = 0;
    for(int i=0;i<n;i++)
    {
        val = val ^ v[i];
        if(val == m)
        {
            ans++;
        }
        int x = val^m;
        if(um.find(x) != um.end())
        {
            ans = ans + um[x];
        }
        um[val]+=1;
    }
    return ans;
}

int Solution::solve(vector<int> &v, int m)
{
    int n = v.size();
    unordered_map<int,int>um;
    um[0] = 1;
    int ans = 0;
    int val = 0;
    for(int i=0;i<n;i++)
    {
        val = val ^ v[i];
        int x = val^m;
        if(um.count(x))
        {
            ans = ans + um[x];
        }
        um[val]+=1;
    }
    return ans;
}