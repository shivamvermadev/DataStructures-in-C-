#include<iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
}*ptr,*rear,*newptr,*start;

Node* createNewNode(int n)
{
	ptr=new Node;
	ptr->data=n;
	ptr->next=NULL;
	return ptr;
}

void insert(Node *np)
{
	if(start==NULL)
		start=np;
	else
	{
		np->next=start;
		start=np;
	}
}

void display(Node *np)
{
	while(np!=NULL)
	{
		cout<<np->data<<"->";
		np=np->next;
	}
}
void deleteAllNodes()
{
	while(start!=NULL)
	{
		ptr=start;
		start=start->next;
		delete ptr;	
	}
}



int main()
{
	start=NULL;
	
	newptr=createNewNode(1);
	insert(newptr);
	newptr=createNewNode(2);
	insert(newptr);
	newptr=createNewNode(3);
	insert(newptr);
	newptr=createNewNode(4);
	insert(newptr);
	newptr=createNewNode(5);
	insert(newptr);
	newptr=createNewNode(6);
	insert(newptr);
		
	display(start);
		
	deleteAllNodes();
	
	display(start);
	cout<<endl<<"hello";
	
	
	return 0;	
		
		

}

