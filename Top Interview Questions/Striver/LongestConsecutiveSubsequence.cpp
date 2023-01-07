class Solution
{
    public:
        int longestConsecutive(vector<int>& v)
        {
            unordered_set<int>us;
            for(auto& i:v)
            {
                us.insert(i);
            }
            int ans = 0;
            for(auto it=us.begin();it!=us.end();it++)
            {
                int val = *it;
                int curr = 1;
                if(us.find(val-1) == us.end())
                {
                    val = val + 1;
                    while(us.find(val) != us.end())
                    {
                        curr++;
                        val++;
                    }
                    ans = max(ans,curr);
                }
            }
            return ans;
        }
};

class Solution {
public:
    int longestConsecutive(vector<int>& v)
    {
        int n = v.size();
        unordered_map<int,bool>um;
        for(int i=0;i<n;i++)
        {
            um[v[i]] = true;
        }
        for(int i=0;i<n;i++)
        {
            if(um.count(v[i]-1) > 0)
            {
                um[v[i]] = false;
            }
        }
        int ans = 0;
         for(int i=0;i<n;i++)
        {
            if(um[v[i]])
            {
                int curr = 1;
                while(um.count(v[i]+curr) > 0)
                {
                    curr++;
                }
                ans = max(ans,curr);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& v)
    {
        unordered_map<int, bool>um;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            um[v[i]] = true;
        }
        for(int i=0;i<n;i++)
        {
            if(um.count(v[i]-1) > 0)
            {
                um[v[i]-1] = false;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(um[v[i]])
            {
                int count = 1;
                while(um.count(v[i]-count))
                {
                    count++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};