#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

void push(Node **top, int x)
{
	Node *ptr = new Node;
	ptr->data = x;
	ptr->next = *top;
	*top = ptr;
}
void pop(Node **top)
{
	if(*top == NULL)
	{
		cout<<"underflow";
		return;
	}
	Node *temp = *top;
	cout<<temp->data<<" ";
	*top = temp->next;
	delete temp;
}
int main()
{
	Node *top = NULL;
	
	push(&top, 2);
	push(&top, 3);
	push(&top, 4);
	push(&top, 5);
	
	pop(&top);
	pop(&top);
	pop(&top);
	pop(&top);
	pop(&top);
	
	
	return 0;
}

