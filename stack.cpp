#include<iostream>
#include<stack>
using namespace std;
stack<int> s1,s2;
void push(int x)
{
	s1.push(x);
}

void pop()
{
	if(s2.empty() && s1.empty())
	{
		cout<<"underflow"<<endl;
		return ;
	}
	else if(s2.empty() && !s1.empty())
	{
	
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
			
		}
		cout<<s2.top()<<endl;
		s2.pop();
	}
	else
	{
		cout<<s2.top()<<endl;
		s2.pop();
	}
}
int main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	
	return 0;	
}
