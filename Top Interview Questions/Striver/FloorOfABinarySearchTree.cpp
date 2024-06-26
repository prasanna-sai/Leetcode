class Solution
{
    public:
        int findFloor(TreeNode* root, int key)
        {
            int floor = -1; 
            while(root)
            {
                if(root->val == key)
                {
                    floor = root->val;
                    return floor;
                } 
                if(key > root->val)
                {
                    floor = root->val;
                    root = root->left;
                }
                else
                {
                    root = root->right;
                }
            }
            return floor;
        }
};
