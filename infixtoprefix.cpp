#include<iostream>
#include<stack>
using namespace std;

stack<char> stck;

string reverse(string s)
{
	string rev;
	for(int i=s.length()-1; i>=0; --i)
	{
		if(s[i]=='(')
			rev = rev + ')';
		else if(s[i]==')')
			rev = rev + '(';
		else
			rev = rev + s[i];
	}
	return rev;
}

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

string infixToPostfix(string s)
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
	return p;
}

int main()
{
	string str = "(a-b/c)*(a/k-l)";
	
	string str1 = infixToPostfix(reverse(str));
	cout<<reverse(str1);
	
	return 0;

}
