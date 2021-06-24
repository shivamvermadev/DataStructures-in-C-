#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int info;
    Node *left, *right;
};
Node* createNode(int x) {
    Node *ptr = new Node;
    ptr->info = x;
    ptr->left = ptr->right = NULL;
    return ptr;
}

// int pos;

// void createFromPreorder(int *a,int n, Node *root, int min, int max) {

//     if(curPos == n || a[curPos] < min || a[curPos] > max) {
//         return;
//     }
    
//     else if(a[curPos] < root->info) {
//         root->left = createNode(a[curPos]);
//         curPos++;
//         createFromPreorder(a, n, root->left,  min, root->info - 1);
//     }

//     else {
//         root->right = createNode(a[curPos]);
//         curPos++;
//         createFromPreorder(a, n, root->right, root->info + 1, max);
//     }
// }

int construct_BST(int *preorder,int n,int pos,Node *curr,int left,int right)
{
    if(pos==n || preorder[pos]<left || preorder[pos]>right) //Boundary case
        return pos;
    
    if(preorder[pos]<curr->info)     //Insert in left-subtree
    {
        curr->left = createNode(preorder[pos]);
        pos += 1;
        pos = construct_BST(preorder,n,pos,curr->left,left,curr->info-1);
    }
    
    if(pos==n || preorder[pos]<left || preorder[pos]>right)
        return pos;
    
    //Insert in right-subtree
    curr->right = createNode(preorder[pos]);
    pos += 1;
    pos = construct_BST(preorder,n,pos,curr->right,curr->info+1,right);
    return pos;
}

void inorder(Node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->info<<" ";
    inorder(root->right);
}

Node* constructBST(int *a, int max, int curPos, int n) {
    if(curPos == n || a[curPos] > max) {
        return NULL;
    }
    int curVal = a[curPos++];
    Node *temp = createNode(curVal);
    temp->left = constructBST(a, curVal - 1, curPos, n);
    temp->right = constructBST(a, curVal + 1, curPos, n);
    return temp;
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int a[] = {8,5,1,7,10,12, 2, 3, 6};
    // pos = 1;
    Node *root = createNode(a[0]);
    // createFromPreorder(a, 7, root, INT_MIN, INT_MAX);    
    int x = construct_BST(a, 9,1, root, INT_MIN, INT_MAX);    
    
    inorder(root);
    Node *head = constructBST(a, INT_MAX, 0, 9);
    cout<<endl;
    inorder(root);
return 0;
}