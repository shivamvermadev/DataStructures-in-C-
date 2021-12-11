#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int n) {
    Node *ptr = new Node;
    ptr->data = n;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void insert(Node **root, int n) {
    if(*root == NULL) {
        *root = createNode(n);
        return;
    }

    queue<Node*> q;
    q.push(*root);
    while(q.empty() == false) {
        Node *node = q.front();
        q.pop();
        if(node->left == NULL) {
            node->left = createNode(n);
            return;
        }
        else {
            q.push(node->left);
        }

        if(node->right == NULL) {
            node->right = createNode(n);
            return;
        }
        else {
            q.push(node->right);
        }
    }
}

void inorder(Node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void BFS(Node *root) {
    if(root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(q.empty() == false) {
        Node *node = q.front();
        q.pop();
        cout<<node->data<<" ";
        if(node->left) {
            q.push(node->left);
        }
        if(node->right) {
            q.push(node->right);
        }
    }
}

void deleteDeepest(Node **root, Node *lastNode) {
    Node *node = *root;

    queue<Node*> q;
    q.push(node);
    while(q.empty() == false) {
        Node *temp = q.front();
        q.pop();
        if(temp == lastNode) {
            temp = NULL;
            delete(temp);
            return;
        }
        if(temp->left) {
            if(temp->left == lastNode) {
                delete(temp->left);
                temp->left = NULL;
                return;
            }
            else {
                q.push(temp->left);
            }
        }

        if(temp->right) {
            if(temp->right == lastNode) {
                delete(temp->right);
                temp->right = NULL;
                return;
            }
            else {
                q.push(temp->right);
            }
        }
    }

}

void deleteNode(Node **root, int n) {
    Node *node = *root;
    if(*root == NULL) {
        return;
    }

    if(node->data == n && node->left == NULL && node->right == NULL) {
        delete(node);
        *root = NULL;
        return;
    }
    Node *delNode = NULL, *temp = NULL;
    queue<Node*> q;
    q.push(node);
    while(q.empty() == false) {
        temp = q.front();
        q.pop();
        if(temp->data == n) {
            delNode = temp;
        }
        if(temp->left) {
            q.push(temp->left);
        }
        if(temp->right) {
            q.push(temp->right);
        }
    }

    if(delNode != NULL) {
        int x = temp->data;
        delNode->data = temp->data;
        deleteDeepest(root, temp);
	}
}

int heightBinaryTree(Node *root) {
	if(root == NULL) {
		return 0;
	}
	return 1 + max(heightBinaryTree(root->left), heightBinaryTree(root->right));
}

void printNodesAtDepthD(Node *root, int d, int currentDepth) {
	if(root == NULL) {
		return;
	}

	if(d == currentDepth) {
		cout<<root->data << " ";
		return;
	}

	printNodesAtDepthD(root->left, d, currentDepth + 1);
	printNodesAtDepthD(root->right, d, currentDepth + 1);
}

Node* f(int *in, int *pre, int inStart, int inEnd,int preStart, int preEnd) {
	if(inStart > inEnd) {
		return NULL;
	}

	Node *root = createNode(pre[preStart]);

	int rootIndex = -1;
	for(int i=inStart;i<=inEnd;++i) {
		if(in[i] == pre[preStart]) {
			rootIndex = i;
			break;
		}
	}

	int leftInStart = inStart;
	int leftInEnd = rootIndex - 1;
	int rightInStart = rootIndex + 1;
	int rightInEnd = inEnd;
	
	int leftPreStart = preStart + 1;
	int leftPreEnd = leftInEnd - leftInStart + leftPreStart; // leftInEnd - leftInStart + leftPreStart= leftPreEnd - leftPreStart
	int rightPreStart = leftPreEnd + 1;
	int rightPreEnd = preEnd;

	root->left = f(in, pre, leftInStart, leftInEnd, leftPreStart, leftPreEnd);
	root->right = f(in, pre, rightInStart, rightInEnd, rightPreStart, rightPreEnd);
	return root;
}

void constructBinaryTreeFromInorderandPreOrder() {
	int n;
	cin>>n;
	int *in = new int[n]{0};
	int *pre = new int[n]{0};

	for(int i=0;i<n;++i) {
		cin>>in[i];
	}

	for(int i=0;i<n;++i) {
		cin>>pre[i];
	}
	
	Node *root = f(in, pre, 0, n-1, 0, n-1);
	BFS(root);
}


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Node *root = NULL;
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 5);
        
    // inorder(root);
    // cout<<"\n";

    // preorder(root);
    // cout<<"\n";

    // postorder(root);
    // cout<<"\n";

    // BFS(root);
    // cout<<"\n";

    // deleteNode(&root, 1);
    // BFS(root);

	// cout<<heightBinaryTree(root);

	// printNodesAtDepthD(root, 1, 0);

	constructBinaryTreeFromInorderandPreOrder();
return 0;
}

