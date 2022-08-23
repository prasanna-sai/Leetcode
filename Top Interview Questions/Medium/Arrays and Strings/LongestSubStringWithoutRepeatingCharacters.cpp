class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> v(256,-1);
        int l = s.length();
        int ans = 0;
        int val = -1;
        //val stores the index of the non repeating number, everytime it see the repeating character it resets to the last index
        //of the repeating character
        for(int i=0;i<l;i++)
        {
            if(v[s[i]] > val)
            {
                val = v[s[i]];
            }
            v[s[i]] = i;
            ans = max(ans,i-val);
        }
        return ans;
    }
};