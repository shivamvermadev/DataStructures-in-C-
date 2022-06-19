#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int data;
    Node *left, *right;
};

void rootToLeaf(Node *root, vector<Node*> &v, int x) {
    if(root == NULL) {
        return;
    }
    
    if(root->data == x)  {
        v.push_back(root);
        return;
    }   
    
    v.push_back(root);
    
    if(x < root->data) {
        rootToLeaf(root->left, v, x);
    }
    else {
        rootToLeaf(root->right, v, x);
    }
}

Node* LCA(Node *root, int n1, int n2)
{
    vector<Node*> v1, v2;
    
    rootToLeaf(root, v1, n1);
    rootToLeaf(root, v2, n2);
    
    int i = 0;
    int j = 0;
    Node *ans = NULL;
    while(i < v1.size() && j < v2.size()) {
        // cout<<v1[i]->data <<"\t" <<v2[j]->data << "\n";
        if(v1[i]->data == v2[j]->data) {
            ans = v1[i];
            i++;
            j++;
        }
        else {
            break;
        }
    }
    return  ans;
}


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    

return 0;
}