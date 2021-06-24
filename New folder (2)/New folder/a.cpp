#include<bits/stdc++.h>
using namespace std;
map<int,char> m1;
map<int,char> m2;

int main()
{
	for(int i=97;i<=122;i++)
	{
		m1[i] = (char)i;
	}
	for(int i=65;i<=90;++i)
	{
		m2[i] = (char)i;
	}

	int s1,s2;
	string str,str1;
	cin>>str;
	reverse(str.begin(),str.end());
	cout<<str<<endl;
	
	for(int i=0;i < str.length();)
	{
		// s1 = (str[i]-'0')*10+(str[i+1]-'0');
		
		// s2 = (str[i]-'0')*100+(str[i+1]-'0')*10 + (str[i+2]-'0');
		
		cout<<s1<<" "<<s2<<endl;

		if(m1.find(s1) != m1.end())
		{
			str1 += m1[s1];
			i = i+2;
			continue;
		}
		if(m2.find(s1) != m2.end())
		{
			str1 += m2[s1];
			i += 2;
			continue;
		}
		if(m1.find(s2) != m1.end())
		{
			str1 += m1[s2];
			i += 3;
			continue;
		}
		if(m2.find(s2) != m2.end())
		{
			str1 += m2[s2];
			i += 3;
			continue;
		}
		else
		{
			i++;
		}
	}
	cout<<str1<<endl;
}