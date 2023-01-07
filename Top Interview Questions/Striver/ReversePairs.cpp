class Solution {
public:
    int reversePairs(vector<int>& nums)
    {
        int n = nums.size();
        return MergeSort(nums, 0, n-1);    
    }

    int MergeSort(vector<int>&v, int start, int end)
    {
        int ans = 0;
        if(start >= end)
        {
            return ans;
        }
        int mid = start + (end-start)/2;
        ans += MergeSort(v, start, mid);
        ans += MergeSort(v, mid+1, end);
        ans += countPairs(v, start, mid, end);
        Merge(v, start, mid, end);
        return ans;
    }

    int countPairs(vector<int> &arr, int low, int mid, int high)
    {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > (long long int)2 * arr[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
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
            if(v1[i] < v2[j])
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