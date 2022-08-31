class Solution {
public:
    int evalRPN(vector<string>& v)
    {
        int ans = 0;
        int n = v.size();
        stack<int>s;
        //Straight forward solution of when you find a symbol get the top two elements
        //Perform the operation and push it back into the stack
        for(int i=0;i<n;i++)
        {
            if(v[i] == "+")
            {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                s.push(val1+val2);
                continue;
            }
            if(v[i] == "-")
            {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                s.push(val2-val1);
                continue;
            }
            if(v[i] == "*")
            {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                s.push(val1*val2);
                continue;
            }
            if(v[i] == "/")
            {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                s.push(val2/val1);
                continue;
            }
            int val = stoi(v[i]);
            s.push(val);
        }
        return s.top();
    }
};