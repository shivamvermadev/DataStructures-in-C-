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

Node* insertLevelWise() {
    Node *root = NULL;
    int x;

    cout<<"Enter the root Data "<<endl; 
    cin>>x;
    root = createNode(x);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        cout<<"Enter the left child of "<<temp->info<<endl;
        cin>>x;
        if(x != -1) {
            Node *leftNode = createNode(x);
            temp->left = leftNode;
            q.push(leftNode);
        }
        cout<<"Enter the right child of "<<temp->info<<endl;
        cin>>x;
        if(x != -1) {
            Node *rightNode = createNode(x);
            temp->right = rightNode;
            q.push(rightNode);
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
void f(Node *root, map<int, list<int> > &map, int dist) {
    if(root == NULL) {
        return;
    }
    map[dist].push_back(root->info);
    f(root->left, map, dist -1);
    f(root->right, map, dist +1);
}

void verticalOrderTraversal(Node *root) {
    if(root == NULL) {
        return;
    }
    map<int,list<int> > map;
    f(root, map, 0);
    for(auto i:map) {
        for(auto j:i.second) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    map.clear();

    cout<<"Another type using the bfs"<<endl;
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()) {
        pair<Node*,int> p = q.front();
        q.pop();
        Node* node = p.first;
        int dist = p.second;
        map[dist].push_back(node->info);
        if(node->left) {
            q.push(make_pair(node->left, dist-1));
        }
        if(node->right) {
            q.push(make_pair(node->right, dist+1));
        }
    }
    for(auto i:map) {
        for(auto j:i.second) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
}

void leftViewRecursive(Node *root, map<int, bool> &visited, int count) {
    if(root == NULL) {
        return;
    }
    if(visited[count] == false) {
        visited[count] = true;
        cout<<root->info<<" ";
    }

    leftViewRecursive(root->left, visited, count+1);
    leftViewRecursive(root->right, visited, count+1);

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
            q.push(NULL);
        }
    }
}

void rightView(Node *root, map<int, bool> &visited, int count) {
    if(root == NULL) {
        return;
    }
    if(visited[count] == false) {
        visited[count] = true;
        cout<<root->info<<" ";
    }
    rightView(root->right, visited, count + 1);
    rightView(root->left, visited, count + 1);
}

void rightViewIterative(Node *root) {
    if(root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        
        if(temp) {
            cout<<temp->info<<" ";
            while(temp != NULL) {
                if(temp->right) {
                    q.push(temp->right);
                }
                if(temp->left) {
                    q.push(temp->left);
                }
                temp = q.front();
                q.pop();
            }
            q.push(NULL);
        }
    }
} 

void topView(Node *root) {
    if(root == NULL) {
        return;
    }
    
    map<int,bool> mdist;
    list<int> list;
    queue<pair<Node*,int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()) {
        pair<Node*,int> p = q.front();
        q.pop();
        Node *node = p.first;
        int dist = p.second;
        if(!mdist[dist]) {
            mdist[dist] = true;
            list.push_back(node->info);
        }

        if(node->left) {
            q.push(make_pair(node->left, dist - 1));
        }
        if(node->right) {
            q.push(make_pair(node->right, dist + 1));
        }
    }

    for(auto i:list) {
        cout<<i<<" ";
    }
}

list<int>  diagnolSum(Node *root) {
	list<int> list;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node *temp = q.front();
		q.pop();
		int ans = 0;
		while(temp != NULL) {
			ans += temp->info;
			if(temp->left) {
				q.push(temp->left);
			}
			temp = temp->right;
		}
		list.push_back(ans);
	}
    return list;
} 


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node *root = insertLevelWise();
    // inorder(root);
    // verticalOrderTraversal(root);
    // inorder(root);
    cout<<endl<<"--------";
    map<int,bool> map;
    // leftViewRecursive(root, map, 0);
    // leftViewIteartive(root);
    // rightView(root, map, 0);
    cout<<endl;
    // rightViewIterative(root);
    // topView(root);
    list<int> list = diagnolSum(root);
    for(auto i:list) {
        cout<<i<<" ";
    }
    
return 0;
}

// 1 2 3 -1 4 -1 -1 -1 5 -1 6 -1 -1 