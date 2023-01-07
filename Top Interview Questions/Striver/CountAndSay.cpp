class Solution
{
    public:
        string countAndSay(int n)
        {
            if(n==1)
            {
                return "1";
            }
            string ans = "1";
            //Straight forward counting the number of consecutive same digits and converting it to string and appending
            while(--n)
            {
                string curr = "";
                int l = ans.length();
                for(int k=0;k<l;k++)
                {
                    int count = 1;
                    while((k<(l-1)) && (ans[k]==ans[k+1]))
                    {
                        count++;
                        k++;
                    }
                    curr = curr + to_string(count) + ans[k];
                }
                ans = curr;
            }
            return ans;
        }
};