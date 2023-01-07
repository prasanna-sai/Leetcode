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

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        if(n==0)
        {
            return 0;
        }
        int ans = 1;
        int start = -1;
        vector<int>v(256,-1);
        for(int i=0;i<n;i++)
        {
            if(v[(int)s[i]]>=start)
            {
                ans = max(ans,i-start);
                start = v[(int)s[i]]+1;
                v[(int)s[i]] = i;
            }
            else
            {
                ans = max(ans,i-start+1);
                v[(int)s[i]] = i;
            }
        }
        return ans;
    }
};