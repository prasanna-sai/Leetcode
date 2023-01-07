class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        return helper(arr1, arr2, n, m, k-1);
    }
    int helper(int A[], int B[], int m, int n, int k)
    {
        if(m == 0)
        {
            return B[k];
        }
        if(n == 0)
        {
            return A[k];
        }
        int m1 = m/2, m2 = n/2;
        if(m1 + m2 < k)
        {
            if(A[m1] < B[m2])
            {
                return helper(A+m1+1,B,m-m1-1,n,k-m1-1);
            }
            else if(A[m1] > B[m2])
            {
                return helper(A,B+m2+1,m,n-m2-1,k-m2-1);
            }
        }
        else
        {
            if(A[m1] < B[m2])
            {
                return helper(A,B,m,m2,k);
            }
            else
            {
                return helper(A,B,m1,n,k);
            }
        }
        return 0;
    }
};