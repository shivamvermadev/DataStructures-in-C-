#include<iostream>
#include<stack>
using namespace std;

bool isOperator(char x) { 
  switch (x) { 
  case '+': 
  case '-': 
  case '/': 
  case '*': 
    return true; 
  } 
  return false; 
} 

void prefixtoinfix(string s)
{
	
	stack<string> st;
	int len = s.length();
	for(int i = len-1; i >= 0; --i)
	{
		
		if(isOperator(s[i]))
		{
		
			string s1 = st.top();  st.pop();
			string s2 = st.top();  st.pop();
			
			string temp  ="(" + s1 + s[i] + s2 + ")";
			st.push(temp);
			
		}
		else
		{
			st.push(string(1, s[i]));
			
		}
	}
	cout<<st.top();
	
}
int main()
{
	string str = "*-A/BC-/AKL";
	
	prefixtoinfix(str);
	return 0;

}
