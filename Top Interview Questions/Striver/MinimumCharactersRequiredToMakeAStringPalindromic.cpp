//Think of AABA string and write the execution for understanding this better

int solve(string A)
{
    string B = A;
    reverse(A.begin(), A.end());
    string x = B + "$" + A;
    int n = x.length();
    vector<int>Z(n,0);
    getZArray(x,n,Z);

    int ans = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(Z[i] == n-i)
        {
            ans = max(ans, Z[i]);
        }
    }
    return n-ans;
}

void getZArray(string& s, int& n, vector<int>& Z)
    {
        int L=0,R=0;

        for(int i=1;i<n;i++)
        {
            if(i>R)
            {
                L = R = i;
                while(R<n && s[R-L] == s[R])
                {
                    R++;
                }
                Z[i] = R-L;
                R--;
            }
            else
            {
                int k = i-L;
                if(Z[k] < R-i+1)
                {
                    Z[i] = Z[k];
                }
                else
                {
                    L = i;
                    while(R<n && s[R-L] == s[R])
                    {
                        R++;
                    }
                    Z[i] = R-L;
                    R--;
                }
            }
        }
    }