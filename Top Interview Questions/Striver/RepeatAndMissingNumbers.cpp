#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>v;
    v.push_back(0);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<=n;i++)
    {
        int idx = abs(v[i]);
        v[idx] *= -1;
    }
    for(int i=0;i<=n;i++)
    {
        if(v[i] > 0)
        {
            cout<<i<<endl;
        }
    }
    return 0;
}