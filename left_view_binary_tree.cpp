#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int data;
    Node *left, *right;
};

void leftViewHelper(Node *root, int curLevel, int &maxLevel, vector<int> &v) {
    
    if(root == NULL) {
        return;
    }
    
    if(curLevel > maxLevel) {
        maxLevel = curLevel;
        v.push_back(root->data);
    }
    
    leftViewHelper(root->left, curLevel + 1, maxLevel, v);
    leftViewHelper(root->right, curLevel + 1, maxLevel, v);
}

vector<int> leftView(Node *root)
{
    vector<int> v;
    int maxLevel = 0;
    leftViewHelper(root, 1, maxLevel, v);
    return v;
}
//------------------------------------------------------
vector<int> leftView(Node *root)
{
    vector<int> v;
    if(root == NULL) {
        return v;
    }
    
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));
    
    map<int, int> m;
    
    while(q.empty() == false) {
        pair<Node*, int> p = q.front();
        q.pop();
        
        Node *temp = p.first;
        int level = p.second;
        
        if(m[level] == false) {
            m[level] = temp->data;
            v.push_back(temp->data);
        }
        
        if(temp->left) {
            q.push(make_pair(temp->left, level+1));
        }
        if(temp->right) {
            q.push(make_pair(temp->right, level+1));
        }
    }
    return v;
    
}


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    

return 0;
}