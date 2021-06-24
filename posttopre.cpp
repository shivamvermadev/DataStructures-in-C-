#include<iostream>
#include<stack>
using namespace std;

void posttopre(string s)
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
			
			st.push(s[i]+s2+s1);
		}
	}
	cout<<st.top();
}
int main()
{
	string str = "ABC/-AK/L-*";
	posttopre(str);
	return 0;
	
}
