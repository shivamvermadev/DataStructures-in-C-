#include<iostream>
using namespace std;

struct Node
{
	int info;
	Node *left, *right;
};

Node* createNode(int n)
{
	Node *ptr = new Node;
	ptr->info = n;
	ptr->left = ptr->right = NULL;
	return ptr;
}

void insert(Node **head, int n)
{
	Node *ptr = *head;
	
	if(ptr == NULL)
		ptr = createNode(n);
	else if(n< ptr->info)
		insert(&(ptr->left), n);
	else 
		insert(&(ptr->right), n);
	*head = ptr;
}

void traverse(Node *head)
{
	Node *ptr = head;

	if(ptr == NULL)
		return;

	traverse(ptr->left);
	cout<<ptr->info<<" ";
	traverse(ptr->right);
}
void minNode(Node *head)
{
	if(head == NULL)
		return ;
	while(head->left != NULL)
		{
			head = head->left;
		}
	cout<<head->info;
}


Node* deleteNode(Node *head, int n)
{	
	if(n < head->info)
	{
		head->left = deleteNode(head->left, n);
		return head;
	}
	else if(n > head->info)
	{
		head->right = deleteNode(head->right, n);
		return head;
	}
	else
	{
		if(head->left == NULL && head->right == NULL)
		{
			delete head;
			return NULL;
		}
		else if(head->left == NULL)
		{
			Node *temp = head->right;
			delete head;
			return temp;
		}
		else if(head->right == NULL)
		{
			Node *temp = head->left;
			delete head;
			return temp;
		}
		else
		{
			Node *suc = head->right;
			Node *sucpar = head->right;
			while(suc->left != NULL)
			{
				sucpar = suc;
				suc = suc->left;
			}
			head->info = suc->info;
			sucpar->left = suc->right;
			delete suc;
			return head;
		}
	}
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

int main()
{
	Node *head = NULL;
	insert(&head,45);
	insert(&head,40);
	insert(&head,23);
	insert(&head,50);
	insert(&head,78);
	insert(&head, 45);
	traverse(head);
	cout<<endl<<endl;
	
	// minNode(head);
	head = deleteNode(head, 23);
	cout<<endl<<endl;
	traverse(head);
	cout<<endl;
	// cout<<isBST_1(head);
	return 0;
}
