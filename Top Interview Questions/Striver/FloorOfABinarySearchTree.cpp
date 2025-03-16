class Solution{

public:
    int floor(Node* root, int x)
    {
        int ans = -1;
        while(root)
        {
            if(root->data == x)
            {
                return x;
            }
            if(root->data > x)
            {
                root = root->left;
            }
            else
            {
                ans = max(ans, root->data);
                root = root->right;
            }
        }
        return ans;
    }
};