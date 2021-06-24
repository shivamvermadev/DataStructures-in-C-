#include<iostream>
#define size 10
using namespace std;

int stack[size];

int top1 = -1;
int top2 = size;

void push1(int x)
{
	if(top2 - top1 == 1)
	{
		cout<<"overflow";
		return;
	}
	else
	{
		top1++;
		stack[top1] = x;
		return;
	}
}
void push2(int x)
{
	if(top2 - top1 == 1)
	{
		cout<<"overflow";
		return;
	}
	else
	{
		
		top2--;
		stack[top2] = x;
		return;
	}
}

void pop1()
{
	if(top1 == -1)
	{
		cout<<"underflow";
		return;
	}
	else
	{
		cout<<stack[top1]<<endl;
		top1--;
		return;
	}
}

void pop2()
{
	if(top2 == size)
	{
		cout<<"underflow";
		return;
	}
	else
	{
		cout<<stack[top2]<<endl;
		top2++;
		return;
	}
}

int main()
{
	push1(1);
	push1(2);
	push1(3);
	push1(4);
	
	push2(5);
	push2(6);
	push2(7);
	push2(8);
	push2(8);
	push2(8);
	push2(8);
	
	pop1();
	pop1();
	pop1();
	pop1();
	
	pop2();
	pop2();
	pop2();
	pop2();
	
	return 0;
}

