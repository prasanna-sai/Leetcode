class Solution
{
    /*
    struct Item{
        int value;
        int weight;
    };
    */
    public:
        static bool compare(Item a, Item b)
        {
            double x = a.value/(a.weight*1.0);
            double y = b.value/(b.weight*1.0);
            return x>y;
        }
        double fractionalKnapsack(int W, Item arr[], int n)
        {
            sort(arr,arr+n,compare);
            int curr = 0;
            double ans = 0.0;

            for (int i = 0; i < n; i++)
            {
                if (curr + arr[i].weight <= W)
                {
                    curr += arr[i].weight;
                    ans += arr[i].value;
                }
                else
                {
                    int remain = W - curr;
                    ans += (arr[i].value / (double) arr[i].weight) * (double) remain;
                    break;
                }
            }
            return ans;
        }   
};