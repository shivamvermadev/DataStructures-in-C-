#include<iostream>
using namespace std;

struct Node
{
	int info, count;
	Node *left, *right;
};

Node* createNode(int n)
{
	Node *ptr = new Node;
	ptr->info = n;
	ptr->count = 1;
	ptr->left = ptr->right = NULL;
	return ptr;
}

void insert(Node **head, int n)
{
	Node *ptr = *head;
	
	if(ptr == NULL)
		ptr = createNode(n);
	else if(ptr->info == n)
		ptr->count ++;
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
	cout<<ptr->info<<"("<<ptr->count<<")";
	traverse(ptr->right);
}

int main()
{
	Node *head = NULL;
	insert(&head,45);
	insert(&head,45);
	insert(&head,45);
	insert(&head,45);
	insert(&head,45);
	insert(&head,45);
	insert(&head,45);
	insert(&head,45);
	
//	insert(&head,40);
//	insert(&head,23);
//	insert(&head,50);
//	insert(&head,78);
//	insert(&head, 45);
	traverse(head);
	return 0;
}
