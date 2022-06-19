#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int data;
    Node *left, *right;
};


vector<int> noSibling(Node* root)
{
    vector<int> v;
    
    if(root == NULL) {
        v.push_back(-1);
        return v;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while(q.empty() == false) {
        Node *temp = q.front();
        q.pop();
        
        if(temp->left == NULL && temp->right != NULL) {
            v.push_back(temp->right->data);
        }
        if(temp->left != NULL && temp->right == NULL) {
            v.push_back(temp->left->data);
        }
        
        if(temp->left) {
            q.push(temp->left);
        }
        if(temp->right) {
            q.push(temp->right);
        }
    }
    
    if(v.size() == 0) {
        v.push_back(-1);
    }
    sort(v.begin(), v.end());
    return v;
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    

return 0;
}