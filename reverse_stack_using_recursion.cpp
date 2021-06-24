#include<iostream>
#include<stack>
using namespace std;

stack<int> st;

void insertAtBottom(int x)
{
	if(st.empty())
		st.push(x);
	else
	{
 		int a = st.top();
		st.pop();
		insertAtBottom(x);
		st.push(a);		
	}
}

void reverse()
{
	if(st.empty())
		return;
	
	int x = st.top();
	st.pop();
	reverse();
	insertAtBottom(x);	
}

int main()
{
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	cout<<"Before Reverse"<<"\n";
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	
	reverse();
	cout<<"\nAfter reverse \n";
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	return 0;
}
