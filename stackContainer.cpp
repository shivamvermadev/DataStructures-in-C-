#include<iostream>
#include<stack>
using namespace std;

int main()
{
	stack<int> s;
	stack<int> s1;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	
	s1.push(7);
	s1.push(8);
	s1.push(7);
	s1.push(9);
	s1.push(10);
	s1.push(7);
	
	while(!s1.empty())
	{
		cout<<s1.top();
		s1.pop();
	}
	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}
	return 0;
}

	
	 
