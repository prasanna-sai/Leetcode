/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    int kthLargest(Node *root, int k)
    {
        int count = 0, ans = 0;
        helper(root, count, ans, k);
        return ans;
    }
    void helper(Node* node, int& count, int& ans, int k)
    {
        if(!node || count>k) return;
        helper(node->right, count, ans, k);
        count++;
        if(count == k )
        {
            ans = node->data;
            return;
        }
        helper(node->left, count, ans, k);
    }
};