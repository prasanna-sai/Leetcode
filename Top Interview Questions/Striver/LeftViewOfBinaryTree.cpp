vector<int> leftView(Node *root)
{
    vector<int>ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        ans.push_back(q.front()->data);
        for(int i=0;i<n;i++)
        {
            Node* temp = q.front();
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return ans;
}