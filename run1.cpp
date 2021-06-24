#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int info;
    vector<Node*> v;
};

Node* insertRecursive() {
    int rootData;
    cout<<"enter root data "<<endl;
    cin>>rootData;
    Node *root = new Node;
    root->info = rootData;
    int children;
    cout<<"Enter number of children "<<endl;
    cin>>children;

    for(int i=0;i<children;++i) {
        Node *node = insertRecursive();
        root->v.push_back(node);
    }
    return root;
}

void printTree(Node *root) {
    if(root == nullptr) {
        return;
    }

    cout<<root->info<<" : ";
    for(int i=0;i<root->v.size();++i) {
        cout<<root->v[i]->info<<", ";
    }
    cout<<"\n";
    for(int i=0;i<root->v.size();++i) {
        printTree(root->v[i]);
    }
}

Node* insertLevelWise() {
    int rootdata;
    cout<<"Enter the root data "<<endl;
    cin>>rootdata;
    Node *root = new Node;
    root->info = rootdata;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        int children;
        cout<<"Enter the number of children of "<<temp->info<<endl;
        cin>>children;
        for(int i=0;i<children;++i) {
            cout<<"Enter the child of : "<<temp->info<<endl;
            cin>>rootdata;
            Node *node = new Node;
            node->info = rootdata;
            temp->v.push_back(node);
            q.push(node);
        }
    }
    return root;
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node *root = NULL;
    // root = new Node();

    // root->info = 1;
    // Node *left = new Node();
    // left->info = 2;
    // Node *right = new Node();
    // right->info = 3;
    // root->v.push_back(left);
    // root->v.push_back(right);
    // root = insertRecursive();
    root = insertLevelWise();
    printTree(root);
return 0;
}