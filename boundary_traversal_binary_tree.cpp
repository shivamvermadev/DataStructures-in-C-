#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:
    void getLeftNodesExceptLeaf(Node *root, vector<int> &v) {
        if(root == NULL) {
            return;
        }
        
        if(root->left == NULL && root->right == NULL) {
            return;
        }
            
        if(root->left) {
            v.push_back(root->data);
            getLeftNodesExceptLeaf(root->left, v);
        }
        else if(root->right) {
            v.push_back(root->data);
            getLeftNodesExceptLeaf(root->right, v);
        }
    }
    
    void getLeafNodes(Node *root, vector<int> &v) {
        if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            v.push_back(root->data);
        }
        
        if(root->left) {
            getLeafNodes(root->left, v);
        }
        if(root->right) {
            getLeafNodes(root->right, v);
        }
    }
    
    void getRightTree(Node *root, vector<int> &v) {
        if(root == NULL) {
            return;
        }
        
        if(root->right) {
            getRightTree(root->right, v);
            v.push_back(root->data);
        }
        else if(root->left) {
            getRightTree(root->left, v);
            v.push_back(root->data);
        }
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> v;
        if(root == NULL) {
            return v;
        }
        v.push_back(root->data);
        
        getLeftNodesExceptLeaf(root->left, v);
        getLeafNodes(root->left, v);
        getLeafNodes(root->right, v);
        getRightTree(root->right, v);
        return v;
        
    }
};

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    

return 0;
}