class Solution
{
    public:
        int firstUniqChar(string s)
        {
            //Store frequency in an array, and check if frequency is greater than one for any character.
            int v[26] = {0};
            int n =s.size();
            for(char i:s) v[i-'a']++;
            for(int i=0;i<n;i++) if(v[s[i]-'a'] == 1) return i;
            return -1;
        }
};
