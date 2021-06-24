#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int info;
    Node *left, *right;
};

Node* createNode(int data) {
    Node *ptr = new Node;
    ptr->info = data;
    ptr->left = ptr->right = NULL;
    return ptr;
}

Node *insertLevelWise() {
    int rootData;
    cout<<"Enter root data "<<endl;
    cin>>rootData;
    Node *root = createNode(rootData);
    queue<Node*> q;
    q.push(root);
    int x;
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();

        cout<<"Enter Left child of "<< temp->info<<endl;
        cin>>x;

        if(x != -1) {
            Node *ptr = createNode(x);
            temp->left = ptr;
            q.push(ptr);
        }

        cout<<"Enter right child of "<< temp->info<<endl;
        cin>>x;

        if(x != -1) {
            Node *ptr = createNode(x);
            temp->right = ptr;
            q.push(ptr);
        }
    }
    return root;
}
void inorder(Node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->info<<" ";
    inorder(root->right);
}

void leftViewIteartive(Node *root) {
    if(root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.front() != NULL) {
        Node *temp = q.front();
        q.pop();
        if(temp) {
            cout<<temp->info<<" ";

            while(temp != NULL) {
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
                temp = q.front();
                q.pop();
            }
        }
        q.push(NULL);
    }
}

void f(Node *root, int l, int r, int &count){
    if(root == NULL) {
        return;
    }
    
    if(root->info >= l && root->info <= r) {
        count++;
    }

    if(root->info > l) {
        f(root->left, l, r, count);
    }
    if(root->info < r) {
        f(root->right, l, r, count);
    }
}



int getCountOfNode(Node *root, int l, int h)
{
    int count = 0;
    f(root, l, h, count);
    return count;
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node *root = insertLevelWise();   
    // inorder(root);   
    // leftViewIteartive(root);   
    int l,r;
    cout<<"Enter the left and right"<<endl;
    cin>>l>>r;
    cout<<getCountOfNode(root, l, r)<<endl;
return 0;
}