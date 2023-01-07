/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.

    static bool compare(Item a, Item b)
    {
        return (a.value/(a.weight*1.0)) > (b.value/(b.weight*1.0));
    }
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        sort(arr, arr+n, compare);
        double ans = 0.0;
        int curr = 0;
        for(int i=0;i<n;i++)
        {
            if(curr + arr[i].weight <= w)
            {
                ans += arr[i].value;
                curr += arr[i].weight;
            }
            else
            {
                int remain = w - curr;
                ans += (remain*arr[i].value)/(arr[i].weight*1.0);
                break;
            }
        }
        return ans;
    }
};