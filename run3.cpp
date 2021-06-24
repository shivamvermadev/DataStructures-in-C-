#include<bits/stdc++.h>
using namespace std;
// #define int long long int

struct Node {
    int info;
    Node *left, *right;
};

Node* createNode(int n) {
    Node *ptr = new Node;
    ptr->info = n;
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
    else {
        insert(&(ptr->right), data);
    }

    *root = ptr;
}

void inorder(Node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->info<<" ";
    inorder(root->right);
}

Node* insertLevelWise() {
    int rootData;
    cout<<"Enter the root data"<<endl;
    cin>>rootData;
    Node *root = createNode(rootData);
    queue<Node*> q;
    int leftChild, rightChild;
    q.push(root);

    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        cout<<"Enter the left child of "<< temp->info<<endl;
        cin>>leftChild;
        if(leftChild != -1) {
            Node *leftNode = createNode(leftChild);
            temp->left = leftNode;
            q.push(leftNode);
        } 
        cout<<"Enter the right child of "<<temp->info<<endl;
        cin>>rightChild;
        if(rightChild != -1) {
            Node *rightNode = createNode(rightChild);
            temp->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void levelOrderTraverSal( Node *root) {
    if(root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        cout<<temp->info << " " ;
        if(temp->left) {
            q.push(temp->left);
        }
        if(temp->right) {
            q.push(temp->right);
        }
    }
}

void verticalPrint(Node *root,int count, map<int,list<int> > &map) {
    if(root == NULL) {
        return;
    }
    map[count].push_back(root->info);
    verticalPrint(root->left, count-1, map);
    verticalPrint(root->right, count+1, map);
}

void verticalPrintBFS(Node *root) {
    if(root == NULL) {
        return;
    }
    
    map<int, list<int> > map;
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()) {
        pair<Node*,int> p = q.front();
        q.pop();
        Node *curNode = p.first;
        int dist = p.second;
        map[dist].push_back(curNode->info);
        if(curNode->left) {
            q.push(make_pair(curNode->left, dist-1));
        }
        if(curNode->right) {
            q.push(make_pair(curNode->right, dist+1));
        }
    }
    for(auto i:map) {
        for(auto j : i.second) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void print_MAX_SUM_LevelHorizontal(Node *root) {
    if(root == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    
    int ans = root->info;

    while(q.empty() == false) {
        int count = q.size();
        int curAns = 0;
        while(count--) {
            Node *temp = q.front();
            q.pop();
            if(temp->left) {
                q.push(temp->left);
                curAns += temp->left->info;
            }
            if(temp->right) {
                q.push(temp->right);
                curAns += temp->right->info;
            }
        }
        ans = max(ans, curAns);
    }
    cout<<ans<<endl;
}

void print_MAX_SUM_LevelVertical(Node *root) {
    if(root == NULL) {
        return;
    }
    map<int,int> map;
    queue<pair<Node*,int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()) {
        pair<Node*,int> p = q.front(); 
        q.pop();
        Node *curNode = p.first;
        int dist = p.second;
        map[dist]+= curNode->info;
        if(curNode->left) {
            q.push(make_pair(curNode->left, dist-1));
        }
        if(curNode->right) {
            q.push(make_pair(curNode->right, dist+1));
        }
    }

    int ans = INT_MIN;

    for(auto i:map) {
        ans = max(ans, i.second);
    }

    cout<<ans<<endl;
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

void leftViewRecursive(Node *root, map<int, bool> &visited, int count) {
    if(root == NULL) {
        return;
    }
    if(!visited[count]) {
        visited[count] = true;
        cout<<root->info<<" ";
    }


    leftViewRecursive(root->left, visited, count+1);
    leftViewRecursive(root->right, visited, count+1);

}



int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // Node *root = NULL;
    int n, x;
    // cin>>n;
    // while(n--) {
    //     cin>>x;
    //     insert(&root, x);
    // }
    // inorder(root);
    Node *root = insertLevelWise();
    // levelOrderTraverSal(root);
    map<int, bool> mp1;
    map<int, list<int> > map;
    // verticalPrint(root, 0, map);
    // for(auto i:map) {
    //     for(auto j:i.second) {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<"----"<<endl;
    // verticalPrintBFS(root);
    // print_MAX_SUM_LevelHorizontal(root);    
    // cout<<endl;
    // print_MAX_SUM_LevelVertical(root);
    // cout<<endl;

    mp1.clear();
    leftViewRecursive(root, mp1, 0);
    
    for(auto i:mp1) {
        cout<<i.second<<" ";
    }
    
    // cout<<endl;
    // leftViewIteartive(root);

return 0;
}

// 1 2 3  4 5 6 7  -1 -1 -1 -1 -1 8 -1 -1  -1 -1
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 10 9 -1 -1 -1 11 -1 -1 -1 12 -1 -1
//  4 2 -5 -2 3 -2 6 -1 -1 -1 -1 -1 -1 -1 -1
