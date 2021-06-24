#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int info;
	Node *left, *right;
};

Node *createNode(int n)
{
	Node *ptr = new Node;
	ptr->info = n;
	ptr->left = ptr->right = NULL;
	return ptr;
}

void insert(Node **root, int n)
{
	Node *ptr = *root;
	if (ptr == NULL)
	{
		*root = createNode(n);
		return;
	}
	queue<Node *> q;
	q.push(ptr);
	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop();
		if (temp->left == NULL)
		{
			temp->left = createNode(n);
			return;
		}
		else
		{
			q.push(temp->left);
		}
		if (temp->right == NULL)
		{
			temp->right = createNode(n);
			return;
		}
		else
		{
			q.push(temp->right);
		}
	}
}

void findRightMost(Node **root, Node *node)
{
	Node *temp;
	queue<Node *> q;
	q.push(*root);

	while (!q.empty())
	{
		temp = q.front();
		q.pop();

		if (temp == node)
		{
			temp = NULL;
			delete (node);
			return;
		}
		if (temp->left)
		{
			if (temp->left == node)
			{
				temp->left = NULL;
				delete (node);
			}
			else
			{
				q.push(temp->left);
			}
		}
		if (temp->right)
		{
			if (temp->right == node)
			{
				temp->right = NULL;
				delete (node);
			}
			else
			{
				q.push(temp->right);
			}
		}
	}
}

void deleteNode(Node **root, int x)
{
	queue<Node *> q;
	q.push(*root);
	Node *temp = NULL;
	Node *keyNode = NULL;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (temp->info == x)
		{
			keyNode = temp;
		}

		if (temp->left)
		{
			q.push(temp->left);
		}

		if (temp->right)
		{
			q.push(temp->right);
		}
	}

	if (keyNode != NULL)
	{
		keyNode->info = temp->info;
		findRightMost(root, temp);
	}
}

void inorder(Node *temp)
{
	if (!temp)
		return;

	inorder(temp->left);
	cout << temp->info << " ";
	inorder(temp->right);
}
// void preorder(Node *ptr)
// {
// 	if(ptr == NULL)
// 		return ;

// 	cout<<ptr->info<<"  ";
// 	preorder(ptr->left);
// 	preorder(ptr->right);
// }

// void postorder(Node *ptr)
// {
// 	if(ptr == NULL)
// 		return;
// 	postorder(ptr->left);
// 	postorder(ptr->right);
// 	cout<<ptr->info<<"  ";
// }

// void bfs(Node *root)
// {
// 	queue<Node*> q;
// 	q.push(root);
// 	while(!q.empty())
// 	{
// 		Node *temp = q.front();
// 		q.pop();
// 		cout<<temp->info<<", ";
// 		if(temp->left)
// 			q.push(temp->left);
// 		if(temp->right)
// 			q.push(temp->right);
// 	}
// }

// bool continuousTree(Node *root)
// {
// 	if(root == NULL)
// 		return true;

// 	if(root->left == NULL && root->right == NULL)
// 	{
// 		return true;
// 	}

// 	if(root->left == NULL)
// 	{
// 		return (abs(root->info - root->right->info) == 1) && continuousTree(root->right);
// 	}

// 	if(root->right == NULL)
// 	{
// 		return (abs(root->info - root->left->info) == 1) && continuousTree(root->left);
// 	}

// 	return (abs(root->info - root->left->info) == 1) && (abs(root->info - root->right->info) == 1) && continuousTree(root->left) && continuousTree(root->right);
// }

// bool isFoldableUtility(Node *n1,Node *n2)
// {
// 	if(n1 == NULL && n2 == NULL)
// 		return true;

// 	if(n1==NULL || n2 == NULL)
// 		return false;

// 	return isFoldableUtility(n1->left,n2->right) && isFoldableUtility(n1->right,n2->left);
// }

// bool isFoldable(Node *root)
// {
// 	if(root == NULL)
// 		return true;
// 	return isFoldableUtility(root->left,root->right);
// }

// void inorderWithOutRecursion(Node *cur)
// {
// 	stack<Node*> st;
// 	st.push(cur);
// 	cur = cur->left;

// 	while(st.empty() == false || cur != NULL)
// 	{
// 		while(cur != NULL)
// 		{
// 			st.push(cur);
// 			cur = cur->left;
// 		}

// 		cur = st.top(); st.pop();
// 		cout<<cur->info;
// 		cur = cur->right;
// 	}
// }

// int maximum(Node *root)
// {
// 	if(root == NULL)
// 		return INT_MIN;
// 	return max(root->info,max(maximum(root->left),maximum(root->right)));
// }

// int minimum(Node *root) {
// 	if(root == NULL) {
// 		return INT_MAX;
// 	}
// 	return min(root->info, min(minimum(root->left), minimum(root->right)));
// }

// bool isBST(Node *root)
// {
// 	int leftMax = maximum(root->left);
// 	int rightMin = minimum(root->right);
// 	bool ans = (root->info > leftMax && root->info <= rightMin && isBST(root->left) && isBST(root->right));
// 	return ans;
// }

void printData(Node *root, int isLeft)
{
	if (root == NULL)
	{
		return;
	}
	if (root->info == -1)
	{
		return;
	}

	if (isLeft)
	{
		cout << root->info << endl;
		return;
	}
	printData(root->left, 1);
	printData(root->right, 0);
}

int main(int argc, char const *argv[])
{
	Node *root = NULL;

	// int t, n;
	// cin>>t;
	// while(t--){
	// 	cin>>n;
	// 	insert(&root, n);
	// }
	insert(&root, 3);
	insert(&root, 2);
	insert(&root, 4);
	insert(&root, 1);
	insert(&root, 3);
	insert(&root, 8);
	insert(&root, 7);

	// if(isFoldable(root))
	// {
	// 	cout<<"YES"<<endl;
	// }
	// else
	// {
	// 	cout<<"NO"<<endl;
	// }
	// if(continuousTree(root))
	// 	cout<<"YES"<<endl;
	// else
	// {
	// 	cout<<"NO"<<endl;
	// }
	// inorder(root);
	// cout<<endl;
	// inorderWithOutRecursion(root);
	// printData(root,1);

	// bfs(root);
	return 0;
}
