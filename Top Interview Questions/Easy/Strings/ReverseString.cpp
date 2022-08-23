class Solution {
public:
    void reverseString(vector<char>& s)
    {
        int l = s.size();
        //Straight forward one
        for(int i=0;i<(l/2);i++)
        {
            swap(s[i],s[l-i-1]);
        }
        return;
    }
};