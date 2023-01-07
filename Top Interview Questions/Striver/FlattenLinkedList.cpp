/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

Node* helper(Node* x, Node* y)
{
    if(!x)
    {
        return y;
    }
    else if(!y)
    {
        return x;
    }
    Node* merged;
    if(x->data < y->data)
    {
        merged = x;
        merged->bottom = helper(x->bottom,y);
    }
    else
    {
        merged = y;
        merged->bottom = helper(x,y->bottom);
    }
    merged->next = NULL;
    return merged;
}

/*  Function which returns the root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
    if(!root)
    {
        return root;
    }
    root->next = flatten(root->next);
    root = helper(root,root->next);
    return root;
}