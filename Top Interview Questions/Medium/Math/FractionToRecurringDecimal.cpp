//For the decimal part to recur, the remainder should recur. So we maintain the remainders we have seen.
// Once we see an existing remainder, we have reached the end of the recurring part enclose it with a ")".
// Moreover, insert the ( to the starting index of the recurring part by maintaining a mapping from each
// remainder to the index of the corresponding digit and using it to retrieve the starting index.

class Solution {
public:
    string fractionToDecimal(int a, int b) {
        string ans = "";
        if (a == 0) return "0";
        if ((a < 0 and b >= 0) or (a >= 0 and b < 0)) ans += "-";
        long long c = abs(a), d = abs(b), demp = c % d;
        ans += to_string(c / d);
        if (demp != 0) ans += ".";
        unordered_map <int, int> m;
        while (demp != 0)
        {
            if (m.find(demp) != m.end())
            {
                ans.insert(m[demp], "(");
                ans += ")";
                break;
            }
            m[demp] = ans.length();
            demp *= 10;
            ans += to_string(demp/d);
            demp %= d;
        }
        return ans;
    }
};