#include<iostream>
#include<stack>
using namespace std;

void posttoinfix(string s)
{
	stack<string> st;
	for(int i = 0; i<s.length();++i)
	{
		if(s[i]>= 'a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
		{
			st.push(string(1,s[i]));
			
		}
		else
		{
			string s1 = st.top();  st.pop();
			string s2 = st.top();  st.pop();
			
			st.push("(" + s2 + s[i] + s1 + ")");
		}
	}
	cout<<st.top();
}
int main()
{
	string str = "ab*c+"; 
	posttoinfix(str);
	return 0;
	
}
