class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& v1, vector<int>& v2)
    {
        stack<int>st;
        unordered_map<int,int>um;
        int n = v2.size();

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && v2[i] > st.top())
            {
                um[st.top()] = v2[i];
                st.pop();
            }
            st.push(v2[i]);
        }
        n = v1.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            if(um.count(v1[i]) > 0)
            {
                ans[i] = um[v1[i]];
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& v1, vector<int>& v2)
    {
        stack<int>st;
        unordered_map<int,int>um;
        int n = v2.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && v2[i] >= st.top())
            {
                st.pop();
            }
            int val = st.empty() ? -1 : st.top();
            um[v[i]] = val;
            st.push(v2[i]);
        }
        n = v1.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            if(um.count(v1[i]) > 0)
            {
                ans[i] = um[v1[i]];
            }
        }
        return ans;
    }
};