#include<iostream>
#include<stack>
using namespace std;

stack<int> st, tp;

void sort()
{
	int temp, temptop;
	while(!st.empty())
	{
		temp = st.top();
		st.pop();
		if(tp.empty() || temp>tp.top())
			st.push(temp);
		else
		{
			temptop = tp.top();
			tp.pop();
			if(temptop > temp)
			{
				st.push(temptop);
				st.push(temp);
			}
		}
	}
	
//	while(!tp.empty())
//	{
//		st.push(tp.top());
//		tp.pop();
//	}
}

int main()
{
	st.push(34);
	st.push(3);
	st.push(32);
	st.push(98);
	st.push(92);
	st.push(23);
	sort();
	while(!st.empty())
	{
		cout<<st.top()<<endl;
		st.pop();
	}
	return 0;
	
}
