class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
        int n = nums.size();
        MergeSort(nums, 0, n-1);
        return nums;
    }

    void MergeSort(vector<int>&v, int start, int end)
    {
        if(start >= end)
        {
            return;
        }
        int mid = start + (end-start)/2;
        MergeSort(v, start, mid);
        MergeSort(v, mid+1, end);
        Merge(v, start, mid, end);
    }

    void Merge(vector<int>&v, int start, int mid, int end)
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
    }
};