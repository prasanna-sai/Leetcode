/*struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool compare(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,compare);
        vector<int>v(n+1,-1);
        int count = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--)
            {
                if(v[j] == -1)
                {
                    ans += arr[i].profit;
                    count+=1;
                    v[j] = arr[i].id;
                    break;
                }
            }
        }
        return {count,ans};
    } 
};