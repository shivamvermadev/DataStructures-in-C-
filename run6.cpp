#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int info;
    Node *left, *right;
};
Node* createNode(int in) {
    Node *ptr = new Node;
    ptr->info = in;
    ptr->left = ptr->right = NULL;
    return ptr;
}
void insertLevelWise(Node **head) {
    cout<<"Enter root data"<<endl;
    int data;
    cin>>data;
    Node *root = new Node;
    root->info = data;
    root->left = root->right = NULL;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        cout<<"Enter left child of "<<temp->info<<endl;
        cin>>data;
        if(data != -1) {
            Node *node = createNode(data); 
            temp->left = node;
            q.push(node);
        }
        cout<<"Enter right child of "<<temp->info<<endl;
        cin>>data;
        if(data != -1) {
            Node *node = createNode(data); 
            temp->right = node;
            q.push(node);
        }
    }
    *head = root;
}
void show(Node *head) {
    queue<Node*> q;
    q.push(head);
    while(!q.empty()) {
        Node *temp = q.front();
        cout<<temp->info<<" ";
        q.pop();
        if(temp->left) {
            q.push(temp->left);
        }
        if(temp->right) {
            q.push(temp->right);
        }
    }
}

Node* lca(Node* root, int n1, int n2) 
{ 
    if (root == NULL) return NULL; 
  
    if (root->info > n1 && root->info > n2) 
        return lca(root->left, n1, n2); 
  
    if (root->info < n1 && root->info < n2) 
        return lca(root->right, n1, n2); 
  
    return root; 
} 

vector<int> rightView(Node *root)
{
    vector<int> v;
    map<int,bool> m;
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()) {
        pair<Node*, int> p = q.front();
        q.pop();
        Node *node = p.first;
        int level = p.second;
        m[level] = node->info;
        if(node->left) {
            q.push(make_pair(node->left, level+1));
        }
        if(node->right) {
            q.push(make_pair(node->right, level+1));
        }
    }
    for(auto i:m) {
        v.push_back(i.second);
    }
    return v;
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node *root = NULL;
    insertLevelWise(&root);    
    show(root);
    cout<<endl;
    cout<<"Enter the two ranges"<<endl;
    // int x, y;
    // cin>>x>>y;
    // cout<<lca(root, x, y)->info<<endl;
    vector<int> v = rightView(root);

return 0;
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1 
// 20 8 22 4 12 -1 -1 -1 -1 10 14 -1 -1 -1 -1 