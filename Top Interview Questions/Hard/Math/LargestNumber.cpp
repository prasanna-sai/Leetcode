bool customsort(string a, string b)
{
    return a+b>b+a;
}
class Solution {
public:
    string largestNumber(vector<int>& v)
    {
        string ans = "";
        vector<string>temp;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            temp.push_back(to_string(v[i]));
        }
        sort(temp.begin(),temp.end(),customsort);
        for(int i=0;i<n;i++)
        {
            ans += temp[i];
        }
        if(ans[0] == '0')
        {
            return "0";
        }
        return ans;
    }
};