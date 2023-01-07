#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        struct Node* left;
        struct Node* right;
        Node(int x)
        {
            data = x;
            left = NULL;
            right = NULL;
        }
};
void diagonalPrint(Node* root)
{
    vector<vector<int>>ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> val;
        while (n--)
        {
            Node* temp = q.front();
            q.pop();
            while (temp)
            {
                val.push_back(temp->data);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                temp = temp->right;
            }
        }
        ans.push_back(val);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        int x = ans[i].size();
        cout<<"[";
        for (int j = 0; j < x-1; j++)
        {
            cout << ans[i][j] << ", ";
        }
        cout << ans[i][x-1]<<"]"<<endl;;
    }
}

Node* buildTree()
{
    int data;
    cin >> data;
    Node* root = new Node(data);
    cin >> data;
    root->left = new Node(data);
    cin >> data;
    root->right = new Node(data);
    cin >> data;
    root->left->left = new Node(data);
    cin >> data;
    root->left->right = new Node(data);
    cin >> data;
    root->right->right = new Node(data);
    cin >> data;
    root->right->right->left = new Node(data);
    cin >> data;
    root->left->right->left = new Node(data);
    return root;
}

int main()
{
    Node* root = buildTree();
    diagonalPrint(root);
    return 0;
}

