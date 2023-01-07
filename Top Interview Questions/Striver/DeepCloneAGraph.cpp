class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        if(!node) return NULL;
        unordered_map<Node*, Node*>um;
        unordered_set<Node*> us,us1;
        Node* root = node;
        queue<Node*>q;
        q.push(node);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(!us.count(temp))
            {
                us.insert(temp);
                um[temp] = new Node(temp->val);
                for(int i=0;i<temp->neighbors.size();i++)
                {
                    if(!us.count(temp->neighbors[i]))
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
            if(!us1.count(temp))
            {
                us1.insert(temp);
                for(int i=0;i<temp->neighbors.size();i++)
                {
                    um[temp]->neighbors.push_back(um[temp->neighbors[i]]);
                    if(!us1.count(temp->neighbors[i]))
                    {
                        q.push(temp->neighbors[i]);
                    }
                }
            }
        }
        return um[root];
    }
};