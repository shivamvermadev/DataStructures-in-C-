#include<iostream>
#define MAX 7
using namespace std;

int A[MAX];
int front = -1, rear = -1;

void enQueue(int item)
{
	if(rear == -1)
		rear=front=0;
	else if((front == 0 && rear == MAX-1)||(front==rear+1))
	{
		cout<<"overflow"<<endl;
		return;
	}
	else 
		rear = rear+1;
		A[rear] = item;
				
}
void deQueue()
{
	if(rear==-1)
	{
			cout<<"underflow"<<endl;
			return ;
	}
	else if(front == rear)
	{
		cout<<A[front];
		front=rear=-1;
	}
	else if(front == MAX-1)
	{
		cout<<A[front];
		front=0;
	}
	else
	{
		cout<<A[front];
		front = front+1;
	}
}



int main()
{
	enQueue(1);
	enQueue(2);
	enQueue(3);
	enQueue(4);
	enQueue(5);
	enQueue(5);
	enQueue(5);
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


