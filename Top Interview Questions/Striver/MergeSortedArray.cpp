class Solution
{
    public:
        void merge(vector<int>& v1, int m, vector<int>& v2, int n)
        {
            //Since we have to store entirely in the first vector, we have to sort them from the end.
            int z = m+n-1;
            int y = n-1;
            int x = m-1;
            while(x>=0 && y>=0)
            {
                if(v1[x]<v2[y])
                {
                    v1[z--] = v2[y--];
                }
                else
                {
                    v1[z--] = v1[x--];
                }
            }
            while(y>=0)
            {
                v1[z--] = v2[y--];
            }
        }
};
