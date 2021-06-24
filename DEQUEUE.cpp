#include<iostream>
#define M 10
using namespace std;

int A[M];
int left, right;
left = -1;
right = -1;

void insertionLeft(int x)
{
	if(left == 0)
		left = M-1;
	else
		left--;
	A[left] = x;
}
void insertionRight(int x)
{
	if(right == M-1)
		right = 0;
	else
		right++;
	A[right] = x;
}

void deletionLeft()
{
	if(left == -1 && right == -1)
	{
		cout<<"DEQUE is emppty"<<endl;
		return;
	}
	else if(left == -1)
	{
		cout<<"cannot delete from left"<<endl;
		return;
	}
	else if(left == 0)
	{
		cout<<A[left]<<endl;
		left = -1
	}
	else
	{
		cout<<A[left]<<endl
		left++;
	}

}
void deletionRight()
{
	if(left == -1 && right == -1)
	{
		cout<<"DEQUE is emppty"<<endl;
		return;
	}
	if(right == -1)
	{
		cout<<"cannot delete form right"<<endl;
		return;
	}
	else if(right == 0)
	{
		cout<<A[right]<<endl;
		right = -1;
	}
	else
	{
		cout<<A[right]<<endl;
		right--;
	}
	
}

int main()
{
	insertionLeft()
	insertionLeft();
	
}
