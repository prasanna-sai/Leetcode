/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        unordered_map<Node*, Node*> um;
        Node* it = head;
        while(it)
        {
            um[it] = new Node(it->val);
            it = it -> next;
        }
        it = head;
        while(it)
        {
            um[it]->next = um[it->next];
            um[it]->random = um[it->random];
            it = it -> next;
        }
        return um[head];
    }
};