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

void insert(Node *head, int n)
{
	if(head == NULL){
		head = createNode(n);
		return;
	}
	Node *temp;
	queue<Node*> q;
	q.push(head);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(!temp->left)
		{
			temp->left = createNode(n);
			break;
		}
		else
			q.push(temp->left);
		if(!temp->right)
		{
			temp->right = createNode(n);
			break;
		}
		else
			q.push(temp->right);			
	}
	
}

void mirror(Node *head)
{
	Node *temp;
	if(head == NULL)
		return ;
	mirror(head->left);
	mirror(head->right);
	temp = head->left;
	head->left = head->right;
	head->right = temp;
}

void inorder(Node *head)
{
	if(head == NULL)
		return ;
	inorder(head->left);
	cout<<head->data<<"  ";
	inorder(head->right);
}
int main()
{
	
	Node* root = createNode(1); 
	insert(root,2);
	insert(root,3);
	insert(root,4);
	insert(root, 5);
	inorder(root);
	cout<<endl;
	mirror(root);
	inorder(root);
	return 0;

}
