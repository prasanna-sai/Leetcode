/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
class Solution
{
    public:
    	void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    	{
			if(root == NULL)
			{
				return;
			}
			if(root->key == key)
			{
				if(root->left != NULL)
				{
					Node* temp = root -> left;
					while(temp->right)
					{
						temp = temp -> right;
					}
					pre = temp;
				}

				if (root->right != NULL)
				{
					Node* tmp = root->right ;
					while (tmp->left)
						tmp = tmp->left ;
					suc = tmp ;
				}
				return;
			}
			if(root->key > key)
			{
				suc = root;
				findPreSuc(root->left, pre, suc, key);
			}
			else
			{
				pre = root;
				findPreSuc(root->right, pre, suc, key);
			}
			return;
    	}
};