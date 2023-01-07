class Solution {
public:
    vector<vector<int>> generate(int n)
    {
        if(n==0)
        {
            return {};
        }
        if(n==1)
        {
            return {{1}};
        }
        vector<vector<int>>ans;
        ans.push_back({1});
        //Calculate in top down fashion
        for(int i=1;i<n;i++)
        {
            vector<int>temp;
            temp.push_back(1);
            for(int j=1;j<i;j++)
            {
                temp.push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};