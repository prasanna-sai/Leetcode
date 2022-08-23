class Solution {
public:
    void rotate(vector<int>& v, int k)
    {
        int l = v.size();
        k = k%l;
        vector<int>v1;
        int val1 = l-k;
        for(int i=val1;i<l;i++)
        {
            v1.push_back(v[i]);
        }
        for(int i=0;i<val1;i++)
        {
            v1.push_back(v[i]);
        }
        for(int i=0;i<l;i++)
        {
            v[i] = v1[i];
        }
        return;
    }
};
