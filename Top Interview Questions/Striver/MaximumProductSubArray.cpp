class Solution {
public:
    int maxProduct(vector<int>& v)
    {
        int ans = INT_MIN;
        int n = v.size();
        int curr = 1;
        for(int i=0;i<n;i++)
        {
            curr = curr*v[i];
            ans = max(ans,curr);
            if(curr == 0)
            {
                curr = 1;
            }
        }
        curr = 1;
        for(int i=n-1;i>=0;i--)
        {
            curr = curr*v[i];
            ans = max(ans,curr);
            if(curr == 0)
            {
                curr = 1;
            }
        }
        return ans;
    }
};

//Kadane's algorithm
class Solution {
public:
    int maxProduct(vector<int>& v)
    {
        int ans = v[0], prod0 = v[0], prod1 = v[0];
        int n = v.size();
        for(int i=1;i<n;i++)
        {
            int x = max({v[i], prod0*v[i], prod1*v[i]});
            prod1 = min({v[i], prod0*v[i], prod1*v[i]});
            prod0 = x;
            ans = max(prod0, ans);
        }
        return ans;
    }
};