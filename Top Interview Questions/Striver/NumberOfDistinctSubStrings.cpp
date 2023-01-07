class TrieNode
{
    public:
        bool isEnd;
        TrieNode* children[26];

        TrieNode()
        {
            isEnd = false;
            for(int i=0;i<26;i++)
            {
                children[i] = NULL;
            }
        }

        bool containsKey(char ch)
        {
            return children[ch - 'a'] != NULL;
        }

        Node* get(char ch)
        {
            return children[ch - 'a'];
        }

        Node* put(char ch, TrieNode* node)
        {
            children[ch - 'a'] = node;
        }

        void setEnd()
        {
            isEnd = true;
        }

        bool isEnd()
        {
            return isEnd;
        }
};

int countDistinctSubstrings(string &s)
{ 
    TrieNode* root = new TrieNode();
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        TrieNode* node = root;
        for (int j = i; j < n; j++) { 
            if (!node->containsKey(s[j]))
            {
                node->put(s[j], new TrieNode());
                ans++;
            }
            node = node->get(s[j]);
        }
    }
    return ans + 1;
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */