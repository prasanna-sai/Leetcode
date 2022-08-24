/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

//Iterative Approach with O(1) space

class Solution {
public:
    Node* connect(Node* root)
    {
        Node* temp = root;
        Node* curr;
        while(temp)
        {
            curr = temp;
            while(curr && curr->left)
            {
                curr->left->next = curr->right;
                if(curr->next)
                {
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }
            temp = temp->left;
        }
        return root;
    }
};

//Iterative with extra space
class Solution {
public:
    Node* connect(Node* root)
    {
        if(!root)
        {
            return NULL;
        }
        queue<Node*> q;
        q.push(root);
        //Traverse from right to left and assign the correct next value using Queue similar to the level order traversal
        while (!q.empty())
        {
            int n = q.size();
            Node* temp = NULL;
            for (int i = 0; i < n; i++)
            {
                Node* p = q.front();
                q.pop();
                p->next = temp;
                temp = p;
                if (p != NULL)
                {
                    if(p->right) q.push(p->right);
                    if(p->left) q.push(p->left);
                }
            }
        }
        return root;
    }
};

//Recursive approach

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return NULL;
        }
        if (root -> left) {
            root -> left -> next = root -> right;
            if (root -> next) {
                root -> right -> next = root -> next -> left;
            }
            connect(root -> left);
            connect(root -> right);
        }
        return root;
    }
};
