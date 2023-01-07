class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node* p = q.front();
                q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                if(!Helper(p))
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    bool Helper(Node* node)
    {
        if(!node->left && !node->right)
        {
            return true;
        }
        int val = 0;
        if(node->left) val+= node->left->data;
        if(node->right) val+= node->right->data;
        return node->data == val;
    }
};