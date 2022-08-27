//Using priority queue
class Solution {
public:
    int findKthLargest(vector<int>& v, int k)
    {
        int n = v.size();
        priority_queue<int>p;
        for(int i=0;i<n;i++)
        {
            p.push(v[i]);
        }
        for(int i=0;i<k-1;i++)
        {
            p.pop();
        }
        return p.top();
    }
};

//Using simple sorting
class Solution {
public:
    int findKthLargest(vector<int>& v, int k)
    {
        int n = v.size();
        sort(v.begin(),v.end());
        return v[n-k];
    }
};

//check the nth_element STL-----> optimized cool feature
