class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int cnt1 = 0, cnt2 = 0, cand1 = -1, cand2 = -1;
        vector<int> res;
        for (int i: nums)
        {
            if (cand1 == i)
            {
                cnt1++;
            }
            else if (cand2 == i)
            {
                cnt2++;
            }
            else if (cnt1 == 0)
            {
                cnt1++;
                cand1 = i;
            }
            else if (cnt2 == 0)
            {
                cnt2++;
                cand2 = i;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (int i: nums)
        {
            if (i == cand1)
            {
                cnt1++;
            }
            else if (i == cand2)
            {
                cnt2++;
            }
        }
        if (cnt1 > (int)nums.size() / 3)
        {
            res.push_back(cand1);
        }
        if (cnt2 > (int)nums.size() / 3)
        {
            res.push_back(cand2);
        }
        return res;
    }
};