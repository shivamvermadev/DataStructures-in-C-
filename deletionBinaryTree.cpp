#include<iostream>
#include<queue>
using namespace std;

struct Node
{
	int info;
	Node *left, *right;
};

Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->info = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}; 
  
/* Inorder traversal of a binary tree*/
void inorder(Node* temp) 
{ 
    if (!temp) 
        return; 
  
    inorder(temp->left); 
    cout << temp->info << " "; 
    inorder(temp->right); 
} 

Node* findRightMost(Node *temp)
{
	while(temp->right != NULL)
	{
		temp=temp->right;
	}
	return temp;
}

void findNode(Node *temp, int x)
{
	queue<Node*> q;
	q.push(temp);
	Node *ptr ;
	while(!q.empty())
	{
		ptr = q.front();
		q.pop();
		if(ptr->info == x)
			break;
		q.push(ptr->left);
		q.push(ptr->right);
		
	}
	if(ptr == NULL)
	{
		cout<<"item not found"<<endl;
		return;
	}
	else
	{
		Node *p = findRightMost(temp);
		ptr->info = p->info;
		delete p;
	}	
}

void insert(Node *temp, int n)
{
	queue<Node*> q;
	q.push(temp);
	
	while(!q.empty())
	{
		Node *temp = q.front();
		q.pop();
		if(!(temp->left))
		{
			temp->left = newNode(n);
			break;
		}		
		else
			q.push(temp->left);
			
		if(!(temp->right))
		{
			temp->right = newNode(n);
			break;
		}
		else
			q.push(temp->right);
			
	}
}

int main() 
{ 
    Node* root = newNode(10); 
    root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8); 
  
    cout << "Inorder traversal before insertion:"; 
    inorder(root); 
  
    int key = 12; 
    insert(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after insertion:"; 
    inorder(root); 
    cout<<endl<<endl;
    findNode(root, 12);
    inorder(root);
    
    
  
    return 0; 
} 
