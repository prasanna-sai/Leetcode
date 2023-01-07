class Node
{
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
        }
};
class LRUCache {
public:
    int cacheCapacity;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int, Node*>um;

    LRUCache(int capacity)
    {
        cacheCapacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node)
    {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }

    void removeNode(Node* node)
    {
        Node* temp1 = node->prev;
        Node* temp2 = node->next;
        temp1->next = temp2;
        temp2->prev = temp1;
    }
    
    int get(int key)
    {
        int ans = -1;
        if(um.count(key))
        {
            ans = um[key]->value;
            removeNode(um[key]);
            addNode(um[key]);
            um.erase(key);
            um[key] = head -> next;
        }
        return ans;
    }
    
    void put(int key, int value)
    {
        if(um.count(key))
        {
            removeNode(um[key]);
            um.erase(key);
        }
        if(um.size() == cacheCapacity)
        {
            um.erase(tail->prev->key);
            removeNode(tail->prev);
        }
        addNode(new Node(key,value));
        um[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */