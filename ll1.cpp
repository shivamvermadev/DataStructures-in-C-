#include<iostream>
using namespace std;
class Node
{
	public:
		int info;
		Node *next;
}*head1 = NULL,*tail, *head=NULL, *mergeHead = NULL;

void push(Node **headref, int data)
{
	Node *ptr = new Node;
	ptr->info = data;
	ptr->next = *headref;
	*headref = ptr;
}
void reverse(Node **head1)
{
	Node *prev = NULL, *current = *head1, *next = NULL;
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head1 = prev;
}
		
	

void merge(Node *head1, Node *head2)
{
	Node *ptr1 = head1, *ptr2 = head2, *node;
	while(ptr1 != NULL && ptr2 != NULL)
	{
	
		node = new Node;
		if(ptr1->info > ptr2->info)
		{
			node->info = ptr1->info;
			ptr1 = ptr1->next;
			node->next = mergeHead;
			mergeHead = node;
			cout<<"IN ptr1";
		}
		else
		{
			node->info = ptr2->info;
			ptr2 = ptr2->next;
			node->next = mergeHead;
			mergeHead = node;
			cout<<"in ptr2";
		}
	}
	while(ptr1 != NULL)
	{
		node = new Node;
		node->info = ptr1->info;
		node->next = mergeHead;
		mergeHead = node;
		ptr1=ptr1->next;
		
	}
	while(ptr2 != NULL)
	{
		node = new Node;
		node->info = ptr2->info;
		node->next = mergeHead;
		mergeHead = node;
		ptr2= ptr2->next;
		
	}
}

void show(Node *head)
{
	Node *ptr= head;
	while(ptr != NULL)
	{
		cout<<ptr->info<<"->";
		ptr = ptr->next;
	}
}
int main()
{
	push(&head, 20);
	push(&head, 13);
	push(&head, 2);
	
	push(&head1, 7);
	push(&head1, 6);
	push(&head1, 0);
	
	reverse(&head);
	reverse(&head1);
	
	merge(head, head1);
	
	reverse(&mergeHead);
	
	
	show(mergeHead);
		return 0;
}

