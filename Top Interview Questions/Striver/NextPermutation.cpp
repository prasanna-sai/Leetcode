class Solution
{
    public:
        void nextPermutation(vector<int>& v)
        {
            int n = v.size();
            for(int i=n-1;i>0;i--)
            {
                if(v[i] > v[i-1])
                {
                    int mn = v[i];
                    int idx = i;
                    for(int j = i+1;j<n;j++)
                    {
                        if(v[j] > v[i-1] && v[j]<mn)
                        {
                            mn = v[j];
                            idx = j;
                        }
                    }
                    swap(v[idx],v[i-1]);
                    sort(v.begin()+i,v.end());
                    return;
                }
            }
            sort(v.begin(),v.end());
            return;
        }
};