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


vector<int> RepeatedNumber(vector<int> &a)
{
    int n = a.size();
    int val = 0;
    for(int i=0;i<n;i++)
    {
        val = val ^ a[i] ^ (i+1);
    }
    int number = val & ~(val-1);
    int num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] & number) != 0)
        {
            num1 = num1 ^ a[i];
        }
        else
        {
            num2 = num2 ^ a[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if ((i & number) != 0)
        {
            num1 = num1 ^ i;
        }
        else
        {
            num2 = num2 ^ i;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == num1) 
        {
            cnt++;
        }
    }
    if(cnt == 2)
    {
        return {num1, num2};
    }
    return {num2, num1};
}
