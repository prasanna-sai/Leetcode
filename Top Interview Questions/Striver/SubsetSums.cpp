class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        helper(arr,ans,N,0,0);
        return ans;
    }
    void helper(vector<int>& arr, vector<int>& ans, int N, int index, int curr)
    {
        if(index>=N)
        {
            ans.push_back(curr);
            return;
        }
        helper(arr,ans,N,index+1,curr);
        helper(arr,ans,N,index+1,curr+arr[index]);
    }
};