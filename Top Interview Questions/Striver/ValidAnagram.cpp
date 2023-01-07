class Solution {
public:
//Store the frequencies of characters of two strings in two separate arrays, and see if they are equal for each character.
    bool isAnagram(string s, string t)
    {
        int sz1 = s.size();
        int sz2 = t.size();
        if(sz1 != sz2)
        {
            return false;
        }
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        for(int i=0;i<sz1;i++)
        {
            v1[(int)s[i] - 97] += 1;
            v2[(int)t[i] - 97] += 1;
        }
        for(int i=0;i<26;i++)
        {
            if(v1[i]!=v2[i])
            {
                return false;
            }
        }
        return true;
    }
};