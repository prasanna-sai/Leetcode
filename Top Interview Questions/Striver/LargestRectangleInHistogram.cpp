class Solution
{
    public:
        int largestRectangleArea(vector<int>& v)
        {
            int ans = 0, n = v.size();
            vector<int>v1(n,0),v2(n,n);
            stack<pair<int,int>>st1,st2;
            for(int i=0;i<n;i++)
            {
                while(!st1.empty() && st1.top().first >= v[i])
                {
                    st1.pop();
                }
                int x = st1.empty() ? -1 : st1.top().second;
                v1[i] = x;
                st1.push(make_pair(v[i],i));
            }
            for(int i=n-1;i>=0;i--)
            {
                while(!st2.empty() && st2.top().first >= v[i])
                {
                    st2.pop();
                }
                int x = st2.empty() ? n : st2.top().second;
                v2[i] = x;
                st2.push(make_pair(v[i],i));
            }
            for(int i=0;i<n;i++)
            {
                ans = max(ans,(v[i]*(v2[i]-v1[i]-1)));
            }
            return ans;
        }
};

class Solution
{
    public:
        int largestRectangleArea(vector<int>& v)
        {
            int ans = 0, n = v.size();
            vector<int>v1(n,0),v2(n,n);
            stack<int>st1,st2;
            for(int i=0;i<n;i++)
            {
                while(!st1.empty() && v[st1.top()] >= v[i])
                {
                    st1.pop();
                }
                int x = st1.empty() ? -1 : st1.top();
                v1[i] = x;
                st1.push(i);
            }
            for(int i=n-1;i>=0;i--)
            {
                while(!st2.empty() && v[st2.top()] >= v[i])
                {
                    st2.pop();
                }
                int x = st2.empty() ? n : st2.top();
                v2[i] = x;
                st2.push(i);
            }
            for(int i=0;i<n;i++)
            {
                ans = max(ans,(v[i]*(v2[i]-v1[i]-1)));
            }
            return ans;
        }
};