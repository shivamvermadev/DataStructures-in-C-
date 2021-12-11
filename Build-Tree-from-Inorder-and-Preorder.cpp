#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct Node
{
    int data;
    Node *left, *right;
};

Node *crateNode(int n)
{
    Node *ptr = new Node;
    ptr->data = n;
    ptr->left = ptr->right = NULL;
    return ptr;
}

Node *buildTree(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }

    int rootData = pre[preS];
    int rootIndex = -1;

    for (int i = inS; i <= inE; ++i)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int leftInS = inS;
    int leftInE = rootIndex - 1;
    int rightInS = rootIndex + 1;
    int rightInE = inE;

    int leftPreS = preS + 1;
    int leftPreE = leftInE - leftInS + leftPreS; // leftInE - leftInS = leftPreE - leftPreS
    int rightPreS = leftPreE + 1;
    int rightPreE = preE;

    Node *root = crateNode(rootData);
    root->left = buildTree(in, pre, leftInS, leftInE, leftPreS, leftPreE);
    root->right = buildTree(in, pre, rightInS, rightInE, rightPreS, rightPreE);
    return root;
}

void inorder(Node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int *pre = new int[n]{0};
    int *in = new int[n]{0};

    for(int i=0;i<n;++i) {
        cin>>pre[i];
    }

    for(int i=0;i<n;++i) {
        cin>>in[i];
    }

    Node *root = buildTree(in, pre, 0, n - 1, 0, n - 1);
    inorder(root);
    cout<<"\n";
    preorder(root);
    return 0;
}