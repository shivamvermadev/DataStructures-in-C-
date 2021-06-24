#include<iostream>
using namespace std;
struct Node
{
	int info;
	Node *next;
	
}*rear=NULL,*front=NULL;
void enQueue(int x)
{
	Node *ptr = new Node;
	ptr->info = x;
	ptr->next = NULL;
	if(rear == NULL)
	front = rear = ptr;
	else
	{
		rear->next=ptr;
		rear=ptr;
	}
}
void deQueue()
{
	if(front == NULL)
	{
		cout<<"underflow"<<endl;
		return;
	}
	cout<<front->info<<endl;
	Node *ptr = front;
	front = front->next;
	delete ptr;
}

int main()
{
	enQueue(1);
	enQueue(2);
	enQueue(3);
	enQueue(4);
	enQueue(5);
	deQueue();
	deQueue();
	deQueue();
	deQueue();
	deQueue();
	deQueue();
	deQueue();

	return 0;
}









