#include<iostream>
#include<stack>
using namespace std;

int precedence(char ch)
{
	if(ch=='^')
		return 3;
	else if(ch=='*' || ch=='/')
		return 2;
	else if(ch=='+' || ch=='-')
		return 1;
	else 
		return -1;
	
}

int operation(int a, int b, char ch)
{
	switch(ch)
	{
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '/':
			return a/b;
		case '*':
			return a*b;
			
	}
		
		 
}

int evaluate(string str)
{
	int n;
	stack<char> op;
	stack<int> val;

	for(int i=0; i<str.length(); ++i)
	{
		if(str[i]==' ')
			continue;
		else if(str[i]=='(')
			op.push(str[i]);
		else if(isdigit(str[i]))
		{
			n=0;
			while(i<str.length() && isdigit(str[i]))
			{
				n = n*10 + (str[i]-'0');
				i++;
			}
			val.push(n);
		}
		else if(str[i]==')')
		{
			int a = val.top();
			val.pop();
			int b = val.top();
			val.pop();
			char c = op.top();
			op.pop();
			val.push(operation(b,a,c));
			op.pop();
		}
		else
		{
			while(!op.empty() && precedence(op.top())>=precedence(str[i]))
			{
				int a = val.top();
				val.pop();
				int b = val.top();
				val.pop();
				char c = op.top();
				op.pop();
				val.push(operation(b,a,c));
			}
			op.push(str[i]);
		}
		
	}
	while(!op.empty())
	{
		int a = val.top();
		val.pop();
		int b = val.top();
		val.pop();
		char c = op.top();
		op.pop();
		val.push(operation(b,a,c));
	}
	return val.top();
	
	
}

int main()
{
	cout << evaluate("10 + 2 * 6") << "\n"; 
    cout << evaluate("100 * 2 + 12") << "\n"; 
    cout << evaluate("100 * ( 2 + 12 )") << "\n"; 
    cout << evaluate("100 * ( 2 + 12 ) / 14"); 
    return 0;
}
