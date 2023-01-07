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
};
class Trie
{
    TrieNode* root;
    public:
        Trie()
        {
            root = new TrieNode();
        }
    
        void insert(string word)
        {
            int l = word.length();
            TrieNode* curr = root;
            for(int i=0;i<l;i++)
            {
                int x = word[i] - 'a';
                if(curr->children[x] == NULL)
                {
                    curr->children[x] = new TrieNode();
                }
                curr = curr->children[x];
            }
             curr->isEnd = true;
        }
        
        bool search(string word)
        {
            int l = word.length();
            TrieNode* curr = root;
            for(int i=0;i<l;i++)
            {
                int x = word[i] - 'a';
                if(curr->children[x] == NULL)
                {
                    return false;
                }
                curr = curr->children[x];
            }
            return curr->isEnd;
        }
        
        bool startsWith(string word)
        {
            int l = word.length();
            TrieNode* curr = root;
            for(int i=0;i<l;i++)
            {
                int x = word[i] - 'a';
                if(curr->children[x] == NULL)
                {
                    return false;
                }
                curr = curr->children[x];
            }
            return true;
        }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */