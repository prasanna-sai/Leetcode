/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }a
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        if(!node)
        {
            return nullptr;
        }
        unordered_map<Node*, Node*> um;
        unordered_set<Node*>us;
        queue<Node*>q;
        q.push(node);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(!um.count(temp))
            {
                um[temp] = new Node(temp->val);
                for(int i=0;i<temp->neighbors.size();i++)
                {
                    if(!um.count(temp->neighbors[i]))
                    {
                        q.push(temp->neighbors[i]);
                    }
                }
            }
        }
        q.push(node);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(!us.count(temp))
            {
                us.insert(temp);
                for(int i=0;i<temp->neighbors.size();i++)
                {
                    um[temp]->neighbors.push_back(um[temp->neighbors[i]]);
                    if(!us.count(temp->neighbors[i]))
                    {
                        q.push(temp->neighbors[i]);
                    }
                }
            }
        }
        return um[node];
    }
};