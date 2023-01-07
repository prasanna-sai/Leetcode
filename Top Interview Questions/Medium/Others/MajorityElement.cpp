class Solution {
public:
    int majorityElement(vector<int>& v)
    {
        //Store frequency of each element in unordered map and returns the element value if
        //frequency exceeds n/2
        unordered_map<int,int>um;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            if(um.count(v[i]) == 0)
            {
                um.insert({v[i],1});
            }
            else
            {
                um[v[i]] += 1;
            }
            if(um[v[i]] > n/2)
            {
                return v[i];
            }
        }
        return 0;
    }
};

//Based on majority of bits set
class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int majority_element = 0;

        for (int i = 0; i < 32; i++) {
            int bit = 1 << i;

            // Count how many numbers have this bit set.
            int bit_count = 0;
            for (int num : nums) {
                if ((num & bit) != 0) {
                    bit_count++;
                }
            }

            // If this bit is present in more than n / 2 elements
            // then it must be set in the majority element.
            if (bit_count > n / 2) {
                majority_element |= bit;
            }
        }

        return majority_element;
    }
}

class Solution {
public:
    int majorityElement(vector<int>& v) {
        int n = v.size();
        int ans = -1;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(count == 0)
            {
                ans = v[i];
            }
            count += (ans == v[i]) ? 1 : -1;
        }
        return ans;
    }
};

