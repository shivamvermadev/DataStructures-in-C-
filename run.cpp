#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
	int info;
	Node *left, *right;
};

Node *createNode(int x){
	if(x == -1){
		return nullptr;
	}

	Node *ptr = new Node;
	ptr->info = x;
	ptr->left = ptr->right = NULL;
	return ptr;
}

Node* insertLevelWise() {
    int rootdata;
    cout<<"Enter the root data "<<endl;
    cin>>rootdata;
    Node *root = createNode(rootdata);
    queue<Node*> q;
    q.push(root);
    
	while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        int children;
        cout<<"Enter the left children of "<<temp->info<<endl;
		int leftData, rightData;
		cin>>leftData;
		if(leftData != -1) {
			Node *leftNode =  createNode(leftData);
			temp->left = leftNode;
			q.push(leftNode);
		}

		cout<<"Enter the right children of "<<temp->info<<endl;
		cin>>rightData;
		if(rightData != -1) {
			Node *rightNode = createNode(rightData);
			temp->right = rightNode;
			q.push(rightNode);
		}
    }

    return root;
}

void insert(Node **root, int data){
	if(*root == NULL){
		*root = createNode(data);
		return;
	}

	queue<Node*> q;
	q.push(*root);

	while(!q.empty()){
		Node *temp = q.front();
		q.pop();

		if(temp->left){
			q.push(temp->left);
		}
		else{
			temp->left = createNode(data);
			break;
		}
		if(temp->right){
			q.push(temp->right);
		}
		else{
			temp->right = createNode(data);
			break;
		}
	}
}

Node* takeInputRecursive() {
	int rootData;
	cin>>rootData;
	if(rootData == -1) {
		return NULL;
	}
	Node *root = new Node;
	root->info = rootData;
	Node *left = takeInputRecursive();
	Node *right = takeInputRecursive();
	root->left = left;
	root->right = right;
	return root;
}
void inorder(Node *root) {
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout<<root->info<<" ";
	inorder(root->right);
}
void show(Node *root){
	queue<Node*> q;
	if(root == NULL){
		return;
	}
	q.push(root);
	while(!q.empty()){
		Node *temp = q.front();
		q.pop();
		if(temp->left){
			q.push(temp->left);
		}
		if(temp->right){
			q.push(temp->right);
		}
		cout<<temp->info<<" ";
	}
}

void findRightMost(Node **root, Node *node)  {
	Node *temp;
	queue<Node*> q;
	q.push(*root);

	while(!q.empty()) {
		temp = q.front();
		q.pop();

		if(temp == node) {
			temp = NULL;
			delete(node);
			return;
		}
		if(temp->left) {
			if(temp->left == node) {
				temp->left = NULL;
				delete(node);
			}
			else{
				q.push(temp->left);
			}
		}
		if(temp->right) {
			if(temp->right == node) {
				temp->right = NULL;
				delete(node);
			}
			else{
				q.push(temp->right);
			}
		}
	}
}

void deleteNode(Node **root,int x) {
	queue<Node*> q;
	q.push(*root);
	Node *temp = NULL;
	Node *keyNode = NULL;
	while(!q.empty()) {
		temp = q.front();
		q.pop();
		if(temp->info == x) {
			keyNode = temp;
		}

		if(temp->left){
			q.push(temp->left);
		}

		if(temp->right){
			q.push(temp->right);
		}
	}

	if(keyNode != NULL) {
		keyNode->info = temp->info;
		findRightMost(root, temp);
	}
}

bool continuousTree(Node *root) {
	if(root == NULL){
		return true;
	}
	if(root->left == NULL && root->right == NULL){
		return true;
	}

	if(root->left == NULL) {
		return (abs(root->info - root->right->info) == 1) && (continuousTree(root->right));
	}
	if(root->right == NULL) {
		return (abs(root->info - root->left->info) == 1 && (continuousTree(root->left)));
	}
	return abs(root->info - root->left->info) == 1 && abs(root->info - root->right->info) == 1 && continuousTree(root->left) && continuousTree(root->right);	
}

void mirrorConversion(Node **root) {
	Node *ptr = *root;
	if(*root == NULL) {
		return;
	}
	mirrorConversion(&(ptr->left));
	mirrorConversion(&(ptr->right));
	swap(ptr->left, ptr->right);
}

bool isFoldable(Node *a, Node *b) {
	if(a == NULL && b == NULL) {
		return true;
	}
	if(a == NULL || b == NULL) {
		return false;
	}
	return isFoldable(a->left, b->right) && isFoldable(a->right, b->left);
}

bool isMirror(Node *a, Node *b) {
	if(a == NULL && b == NULL) {
		return true;
	}
	if(a != NULL && b != NULL && a->info == b->info) {
		return isMirror(a->left, b->right) && isMirror(a->right, b->left);
	}
	return false;
}

void inorderIterative(Node *root) {
	if(root == NULL) {
		return;
	}

	stack<Node*> s;
	s.push(root);
	Node *current = root->left;
	while(current != NULL || s.empty() == false) {
		if(current != NULL) {
			s.push(current);
			current = current->left;
		}
		
		if(current == NULL) {
			Node *top = s.top();
			cout<<top->info<<" ";
			s.pop();
			current = top->right;
		}
	}
}

int height(Node *root) {
	if(root == NULL) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

void printAtLevelK(Node *root, int k) {
	if(k == 1 && root != NULL) {
		cout<<root->info<<"\n";
		return;
	}
	if(root == nullptr) {
		return;
	}

	printAtLevelK(root->left, k-1);
	printAtLevelK(root->right, k-1);
}

int diameter(Node *root) {
	if(root == NULL) {
		return 0;
	}

	int option1 = height(root->left) + height(root->right);
	int option2 = diameter(root->left);
	int option3 = diameter(root->right);

	return max(option1, max(option2, option3));
}

pair<int,int> diameterHeight(Node *root) {
//first : height  
//second : diameter
	if(root == NULL) {
		pair<int,int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}

	pair<int,int> leftAns = diameterHeight(root->left);
	pair<int,int> rightAns = diameterHeight(root->right);

	int ld = leftAns.second;
	int lh = leftAns.first;
	int rd = rightAns.second;
	int rh = rightAns.first;
	int height = 1 + max(lh, rh);
	int diameter = max(lh+rh, max(ld, rd));
	pair<int,int> p;
	p.first = height;
	p.second = diameter;
	return p;
}

int maximum(Node *root) {
	if(root == NULL) {
		return INT_MIN;
	}
	return max(root->info, max(maximum(root->left), maximum(root->right)));
}

int minimum(Node *root) {
	if(root == NULL) {
		return INT_MAX;
	}
	return min(root->info, min(minimum(root->left), minimum(root->right)));
}

bool isBST_1(Node *root) {
	if(root == NULL) {
		return true;
	}
	int leftMax = maximum(root->left);
	int rightMin = minimum(root->right);
	int ans = isBST_1(root->left) && isBST_1(root->right) && (root->info > leftMax) && (root->info <= rightMin);
	return ans;
}

struct ReturnType {
	bool isBST;
	int minimum;
	int maximum;
};

ReturnType isBST2(Node *root) {
	ReturnType output;
	if(root == NULL) {
		output.isBST = true;
		output.minimum = INT_MAX;
		output.maximum = INT_MIN;
		return output;
	}
	ReturnType leftAns = isBST2(root->left);
	ReturnType rightAns = isBST2(root->right);

	int minimum = min(root->info, min(leftAns.minimum, rightAns.minimum));
	int maximum = max(root->info, max(leftAns.maximum, rightAns.maximum));
	bool isBSTfinal = (root->info > leftAns.maximum) && (root->info <= rightAns.minimum) && leftAns.isBST && rightAns.isBST;
	output.isBST = isBSTfinal;
	output.minimum = minimum;
	output.maximum = maximum;
	return output;
}

bool isBST3(Node *root,int min = INT_MIN, int max = INT_MAX) {
	if(root == NULL) {
		return true;
	}
	
	if(root->info < min || root->info > max) {
		return false;
	}

	bool leftAns = isBST3(root->left, min, root->info-1);
	bool rightAns = isBST3(root->right, root->info, max); 
	return leftAns && rightAns;
}

int32_t main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Node *root = NULL;
	// int n;
	// cin>>n;
	// int x;
	// while(n--){
	// 	cin>>x;
	// 	insert(&root, x);
	// }
	// show(root);
	// // cin>>x;
	// // deleteNode(&root, x);
	// cout<<"\n";
	// show(root);	
	cout<<"\n";
	// cout<<continuousTree(root);
	// mirror(&root);
	// show(root);
	// cout<<"\n";
	// cout<<isFoldable(root->left, root->right)<<"\n";
	// cout<<isMirror(root, root);
	// inorderIterative(root);
	// cout<<height(root);
	// printAtLevelK(root, 3);
	// Node *root1 = takeInputRecursive();
	root = insertLevelWise();
	// show(root);
	// cout<<"\n";

	cout<<diameter(root);
	pair<int,int> p = diameterHeight(root);
	cout<<"height is : "<<p.first<<"\n";
	cout<<"diameter is : "<<p.second<<"\n";
	// show(root);
	// cout<<"\n";
	inorder(root);
	cout<<endl;
	cout<<isBST_1(root);
	ReturnType output = isBST2(root);
	cout<<endl<<output.isBST;
return 0;
}


// 4 2 6 1 3  5 7 -1 -1 -1 -1 -1 -1 -1 -1