vector<int> Solution::prevSmaller(vector<int> &v)
{
    int n = v.size();
    stack<int>st;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top() >= v[i])
        {
            st.pop();
        }
        int x = st.empty() ? -1 : st.top();
        ans.push_back(x);
        st.push(v[i]);
    }
    return ans;
}
