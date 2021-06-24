#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int info;
    Node *left, *right;
};

Node* constructTree(int *in,int *pre, int inStart, int inEnd, int preStart, int preEnd) {
    if(inStart > inEnd) {
        return NULL;
    }

    int rootData = pre[preStart];
    int rootIndex = -1;

    for(int i=inStart;i<=inEnd;++i){
        if(rootData == in[i]) {
            rootIndex = i;
            break;
        }
    }

    Node *root = new Node;
    root->info = rootData;

    int l_in_start = inStart;
    int l_in_end = rootIndex - 1;
    int r_in_start = rootIndex + 1;
    int r_in_end = inEnd;
    
    int l_pre_start = preStart + 1;
    int l_pre_end = l_in_end - l_in_start + l_pre_start;
    
    int r_pre_start = l_pre_end + 1;
    int r_pre_end = preEnd;

    root->left = constructTree(in, pre, l_in_start, l_in_end, l_pre_start, l_pre_end);
    root->right = constructTree(in, pre, r_in_start, r_in_end, r_pre_start, r_pre_end);
    return root;
}


void show(Node *root) {
    if(root  == NULL) {
        return;
    }
    show(root->left);
    cout<<root->info<<" ";
    show(root->right);
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;

    int *pre = new int[n]{0};
    int *in = new int[n]{0};
    for(int i=0;i<n;++i) {
        cin>>pre[i];
    }
    
    for(int i=0;i<n;++i) {
        cin>>in[i];
    }
    
    int inStart = 0, preStart = 0;
    int inEnd = n-1, preEnd = n-1;
    Node *root = constructTree(in, pre, inStart, inEnd, preStart, preEnd);
    show(root);
return 0;
}