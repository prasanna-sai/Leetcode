class Solution
{
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
        {
            //Sort the arrays and use two pointers each on each separate arrays to merge them and avoid duplicates
            sort(nums1.begin(),nums1.end());
            sort(nums2.begin(),nums2.end());
            int n1 = nums1.size();
            int n2 = nums2.size();
            vector<int>ans;
            int i=0;
            int j=0;
            while(i<n1 && j<n2)
            {
                if(nums1[i] == nums2[j])
                {
                    ans.push_back(nums1[i]);
                    i++;
                    j++;
                    continue;
                }
                if(nums1[i]<nums2[j])
                {
                    i++;
                    continue;
                }
                j++;
            }
            return ans;
        }
};
