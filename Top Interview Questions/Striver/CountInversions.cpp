class Solution {
public:
    long long int inversionCount(long long arr[], int n)
    {
        vector<long long int>nums(n);
        for(int i=0;i<n;i++)
        {
            nums[i] = arr[i];
        }
        return MergeSort(nums, 0, n-1);
    }

    long long int MergeSort(vector<long long int>&v, int start, int end)
    {
        long long int ans = 0;
        if(start >= end)
        {
            return ans;
        }
        int mid = start + (end-start)/2;
        ans += MergeSort(v, start, mid);
        ans += MergeSort(v, mid+1, end);
        ans += Merge(v, start, mid, end);
        return ans;
    }

    int Merge(vector<int>&v, int start, int mid, int end)
    {
        int x = mid - start + 1;
        int y = end - mid;
        vector<int>v1(x), v2(y);
        for(int i=start;i<=mid;i++)
        {
            v1[i-start] = v[i];
        }
        for(int i=mid+1;i<=end;i++)
        {
            v2[i-mid-1] = v[i];
        }
        long long int ans = 0;
        int i = 0, j = 0, k = start;
        while(i<x && j<y)
        {
            if(v1[i] <= v2[j])
            {
                v[k] = v1[i];
                i++;
            }
            else
            {
                ans += (x-i);
                v[k] = v2[j];
                j++;
            }
            k++;
        }
        while(i<x)
        {
            v[k] = v1[i];
            i++;
            k++;
        }
        while(j<y)
        {
            v[k] = v2[j];
            j++;
            k++;
        }
        return ans;
    }
};