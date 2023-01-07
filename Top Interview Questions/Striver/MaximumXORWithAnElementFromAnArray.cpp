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
        vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& v)
        {
            int n = nums.size();
            sort(nums.begin(), nums.end());

            int m = v.size();
            vector<pair<int, pair<int,int>>> q;
            for(int i=0;i<m;i++)
            {
                q.push_back(make_pair(v[i][1], make_pair(v[i][0],i)));
            }
            sort(q.begin(), q.end());
            
            vector<int>ans(m,0);
            int i=0;

            for(int k=0;k<m;k++)
            {
                while(i < n && nums[i] <= q[k].first)
                {
                    insert(nums[i]); 
                    i++;
                }
                
                if(i != 0)
                {
                    ans[q[k].second.second] = helper(q[k].second.first);
                }
                else
                {
                    ans[q[k].second.second] = -1;
                }
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