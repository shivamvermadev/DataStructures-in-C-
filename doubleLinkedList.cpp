#include<iostream>
using namespace std;

class Node
{
	public:
		int info;
		Node *prev, *next;
} *save, *backHead;

void insert(Node **head, int data)
{
	Node *ptr = new Node;
	ptr->info = data;
	if(*head == NULL)
	{
		backHead = ptr;
		ptr->next = *head;
		save = ptr;
		*head = ptr;
		ptr->prev = NULL;
	}
	else
	{
		ptr->next = *head;
		*head = ptr;
		save->prev = ptr;
		save = ptr;
		ptr->prev = NULL;
	}
}

void show(Node *head)
{
	Node *ptr = head;
	while(ptr != NULL)
	{
		cout<<ptr->info<<"  ";
		ptr=ptr->next;
	}
	ptr=backHead;
	cout<<endl;
	while(ptr != NULL)
	{
		cout<<ptr->info<<"  ";
		ptr = ptr->prev;
	}
}

void fun(Node *head){
	Node *current = head;
	Node *temp = NULL;
	while(current != NULL){
		temp = current->prev;
		current->prev = current->next;
		current->prev = temp;
		current = current->prev;
	}
	if(temp != NULL){
		head = temp->prev;
	}
	cout<<"alkdgkljadlgkjasdgjkadlgadkjgf";
	show(head);
}

int main()
{
	Node *head = NULL;
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 5);
	insert(&head, 6);

	// show(head);
	cout<<endl<<endl;
	fun(head);
	return 0;
}

		
		
	
