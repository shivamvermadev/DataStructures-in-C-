#include<iostream>
#include<stack>
using namespace std;

void balancedParanthesis(string s)
{
	stack<char> st;
	for(int i=0; i< s.length(); ++i)
	{
		if(s[i]=='(' || s[i]=='{' || s[i]=='[')
			st.push(s[i]);
			
			
		else if(s[i]==')' && st.top()=='(')
			st.pop();
		else if(s[i]=='}' && st.top()=='{')
			st.pop();
		else if(s[i]==']' && st.top()=='[')
			st.pop();

	}

	if(st.empty())
		cout<<"well balanced paranthesis";
	else 
		cout<<"not balanced";
}
int main()
{
	balancedParanthesis("{()}[]");
	return 0;
}
