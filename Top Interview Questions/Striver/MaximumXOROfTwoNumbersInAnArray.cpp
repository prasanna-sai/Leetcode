class TrieNode
{
    public:
        TrieNode* children[2];
        TrieNode()
        {
            children[0] = NULL;
            children[1] = NULL;
        }
        bool containsKey(int x)
        {
            return children[x] != NULL;
        }

        TrieNode* get(int x)
        {
            return children[x];
        }

        void put(int x, TrieNode* node)
        {
            children[x] = node;
        }
};

class Solution
{
    TrieNode* root = new TrieNode();

    void insert(int x)
    {
        TrieNode* temp = root;
        bitset<32>bs(x);
        for(int i=31;i>=0;i--)
        {
            if(!temp->containsKey(bs[i]))
            {
                temp->put(bs[i], new TrieNode());
            }
            temp = temp->get(bs[i]);
        }
    }

    public:
        int findMaximumXOR(vector<int>& nums)
        {
            int n = nums.size();
            TrieNode* node = root;
            for(int i=0;i<n;i++)
            {
                insert(nums[i]);
            }
            int ans = 0;
            for(int i=0;i<n;i++)
            {
                ans = max(ans, helper(nums[i]));
            }
            return ans;
        }

        int helper(int x)
        {
            TrieNode* temp = root;
            bitset<32>bs(x);
            int ans = 0;
            for(int i=31;i>=0;i--)
            {
                if(temp->containsKey(!bs[i]))
                {
                    ans = ans + (1<<i);
                    temp = temp->get(!bs[i]);
                }
                else
                {
                    temp = temp->get(bs[i]);
                }
            }
            return ans;
        }
};