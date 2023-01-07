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
                    int val = v[i-1];
                    int currMin = v[i];
                    int swapIndex = i;
                    for(int j=i+1;j<n;j++)
                    {
                        if(v[j] > val && v[j] < currMin)
                        {
                            swapIndex = j;
                            currMin = v[j];
                        }
                    }
                    swap(v[i-1],v[swapIndex]);
                    sort(v.begin()+i, v.end());
                    return;
                }
            }
            sort(v.begin(),v.end());
            return;
        }
};