class Solution {
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string>v;
        //Simple If and Else conditions
        for(int i=1;i<=n;i++)
        {
            if(i%15 == 0)
            {
                v.push_back("FizzBuzz");
            }
            else if(i%3 == 0)
            {
                v.push_back("Fizz");
            }
            else if(i%5==0)
            {
                v.push_back("Buzz");
            }
            else
            {
                string s = to_string(i);
                v.push_back(s);
            }
        }
        return v;
    }
};