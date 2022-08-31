class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        unordered_map<char,int>mp;
        //count the occurances of each task and store the max occurance value
        int count = 0;
        for(auto e : tasks)
        {
            mp[e]++;
            count = max(count, mp[e]);
        }
        int ans = (count-1)*(n+1);
        //ans stores the spots required for storing the max element occurances -1
        //pattern is A***A***A we won't include last A as of now
        for(auto e : mp) if(e.second == count) ans++;
        //add 1 to answer for every last instance of max frequency element
        return max((int)tasks.size(), ans);
        //Now if the total elements is greated than the current answer, we return the total elements
        //because we can insert the remaining elements in between the repeated elements
    }
};