#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char info;
	Node *left,*right;
};

Node *createNode(char data)
{
	Node *ptr = new Node;
	ptr->info = data;
	ptr->left = ptr->right = NULL;
	return ptr;
}

void inorder(Node *root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->info<<" ";
	inorder(root->right);
}

void constructTree(string str)
{
	stack<Node*> s;
	Node *ptr;

	for(int i=0;i<str.length();++i)
	{
		if((str[i] >='A' && str[i] <='Z')||(str[i] >='a' && str[i] <='z'))
		{
			ptr = createNode(str[i]);
			s.push(ptr);
		}
		else
		{
			Node *x = s.top(); s.pop();
			Node *y = s.top(); s.pop();
			ptr = createNode(str[i]);
			ptr->left = y;
			ptr->right = x;
			s.push(ptr);
		}
	}
	inorder(s.top());
}

int main(int argc, char const *argv[])
{
	string str = "ab+ef*g*-";
	constructTree(str);
	
	return 0;
}
