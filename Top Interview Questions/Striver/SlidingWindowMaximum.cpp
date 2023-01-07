//Using Priority Queue
class Solution
{
    public:
        vector<int> maxSlidingWindow(vector<int>& v, int k)
        {
            vector<int>ans;
            int n = v.size();
            priority_queue<pair<int,int>>pq;
            for(int i=0;i<k;i++)
            {
                pq.push(make_pair(v[i],i));
            }
            ans.push_back(pq.top().first);
            for(int i=k;i<n;i++)
            {
                pq.push(make_pair(v[i],i));
                while(pq.top().second <= i-k)
                {
                    pq.pop();
                }
                ans.push_back(pq.top().first);
            }   
            return ans; 
        }
};


//Using Deque
class Solution
{
    public:
        vector<int> maxSlidingWindow(vector<int>& v, int k)
        {
            vector<int>ans;
            int n = v.size();
            deque<int>dq;
            for(int i=0;i<k;i++)
            {
                while(!dq.empty() && v[dq.back()]<=v[i])
                {
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            ans.push_back(v[dq.front()]);
            for(int i=k;i<n;i++)
            {
                while(!dq.empty() && dq.front()<=i-k)
                {
                    dq.pop_front();
                }
                while(!dq.empty() && v[dq.back()]<=v[i])
                {
                    dq.pop_back();
                }
                dq.push_back(i);
                ans.push_back(v[dq.front()]);
            }   
            return ans; 
        }
};