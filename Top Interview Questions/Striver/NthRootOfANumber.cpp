#include<bits/stdc++.h>
using namespace std;
int helper(int n, int m, int mid)
{
    long long ans = 1;
    for(int i=0;i<n;i++)
    {
        ans = ans * mid;
        if(ans > m)
        {
            return 2;
        }
    }
    if(ans == m)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int low = 1, high = m;
    while(low <= high)
    {
        int mid = (low + high)/2;
        int x = helper(n,m,mid);
        if(x == 1)
        {
            cout<<mid<<endl;
            break;
        }
        else if(x == 2)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout<<-1<<endl;
    return 0;
}