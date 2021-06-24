#include<iostream>
#include<queue>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node* createNode(int n)
{
	Node *ptr = new Node;
	ptr->data = n;
	ptr->left = ptr->right = NULL;
	return ptr;
}

void binaryTree(Node *node, int n)
{
	queue<Node*> q;
	q.push(node);
	while(!q.empty())
	{
		Node *temp = q.front();
		q.pop();
		if(temp->left == NULL)
		{
			temp->left = createNode(n);
			break;
		}
		else
			q.push(temp->left);
		if(temp->right == NULL)
		{
			temp->right = createNode(n);
			break;
		}
		else 
			q.push(temp->right);
	}
}

void inorder(Node *head)
{
	if(head == NULL)
		return;
	
	inorder(head->left);
	cout<<head->data<<"  ";
	inorder(head->right);
	
}

int main()
{
	Node *head = NULL;
	head = createNode(10);
	binaryTree(head, 2);
	binaryTree(head, 7);
	binaryTree(head, 8);
	binaryTree(head, 4);
	inorder(head);
	return 0;
}
