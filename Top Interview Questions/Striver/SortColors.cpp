class Solution
{
    public:
        //This is a single pass algorithm
        void sortColors(vector<int>& a)
        {
            int n = a.size();
            int i=0,j=0,k=n-1;
            while(j<=k)
            {
                int cur = a[j];
                switch(cur) 
                {
                    case 0: 
                        std::swap(a[i],a[j]);
                        ++i;
                        ++j;
                        break;
                    case 1:
                        ++j;
                        break;
                    case 2:
                        std::swap(a[j],a[k]);
                        --k; //Here we don't want to do j++ because, we want to process the swapped element
                        break;
                }
            }
        }
};

//We can do the counting sort, but it is not a single pass algorithm