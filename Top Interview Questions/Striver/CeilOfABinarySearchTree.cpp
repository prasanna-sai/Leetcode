int findCeil(Node* root, int x)
{
    int ans = INT_MAX;
    while(root)
    {
        if(root->data == x)
        {
            return x;
        }
        if(root->data < x)
        {
            root = root->right;
        }
        else
        {
            ans = min(ans, root->data);
            root = root->left;
        }
    }
    return ans==INT_MAX ? -1 : ans;
}