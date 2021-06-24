#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int info;
    Node *left;
    Node *right;
};

Node* createNode(int x) {
    Node *ptr = new Node;
    ptr->info = x;
    ptr->left = ptr->right = NULL;
    return ptr;
}

void insert(Node **root, int data) {
    Node *ptr = *root;
    if(ptr == NULL) {
        ptr = createNode(data);
    }
    else if(data < ptr->info) {
        insert(&(ptr->left), data);
    }
    else{
        insert(&(ptr->right), data);
    }
    *root = ptr;
}

void inorder(Node *root) {
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->info<<" ";
    inorder(root->right);
}

void printRange(Node *root, int left, int right) {
    if(root == NULL) {
        return;
    }
    
    if(root->info > left) {
        printRange(root->left, left, right);
    }
    if(root->info >= left && root->info <= right) {
        cout<<root->info<<" ";
    }
    if(root->info < right) {
        printRange(root->right, left, right);
    }
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node *root = NULL;
    int n;
    cin>>n;
    int x;
    while(n--) {
        cin>>x;
        insert(&root, x);
    }

    // inorder(root);
    int left, right;
    // cin>>left>>right;
    // printRange(root, left, right);

return 0;
}