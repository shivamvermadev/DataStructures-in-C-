#include<iostream>
#include<stack>
using namespace std;

stack<char> stck;

int prec(char c)
{
	if(c == '^')
		return 3;
	else if(c == '*' || c == '/')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else 
		return -1;
		
}

void infixToPostfix(string s)
{
	stck.push('(');
	s = s + ')';
	
	string p;
	
	int len = s.length();
	
	for(int i=0; i<len; ++i)
	{
		
		char ch = s[i];
		if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		{
			p = p + ch;
		}
		else if(ch == '(')
			stck.push(ch);
			
		else if(ch == ')')
		{
			while(stck.top() != '(')
			{
				p = p + stck.top();
				stck.pop();
			}
			stck.pop();	
		}
		else
		{
			while(prec(ch) <= prec(stck.top()))
			{
				p = p + stck.top();
				stck.pop();
			}
			stck.push(ch);
			
		}
	}
	cout<<p;
}

int main()
{
	string str = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(str);

	return 0;

}
