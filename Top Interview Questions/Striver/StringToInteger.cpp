class Solution {
public:
    int myAtoi(string str)
    {
        int n = str.size();
        int sign = 1;
        long result = 0;
        int cur = 0;
        //Remove the leading whitespaces
        while(str[cur] != '-' && str[cur] != '+' && !isdigit(str[cur]))
        {
            if(str[cur] == ' ')
                cur++;
            else
               return result; 
        }
        //Find the sign of the integer
        if(str[cur] == '-')
        {
            sign = -1;
            cur++;
        }
        else if(str[cur] == '+')
        {
            cur++;
        }
        //Convert string to integer
        for(int i =cur ; i < n && isdigit(str[i]);i++)
        {
            result = result*10 + (str[i] - '0');
            //Condition to check if it overflows
            if(result*sign >= INT_MAX) return INT_MAX;
            if(result*sign <= INT_MIN) return INT_MIN; 
      
        }
        return result*sign;
    }
};