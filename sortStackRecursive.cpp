#include<iostream>
#include<stack>
using namespace std;

stack<int> st;

void sort(int x)
{
	if(st.empty() || x>st.top())
		st.push(x);
	else
	{
		int a = st.top();
		st.pop();
		sort(x);
		st.push(a);
	}
}

void goTillEnd()
{
	if(st.empty())
		return ;
	int x = st.top();
	st.pop();
	goTillEnd();
	sort(x);

}
int main()
{
	st.push(5);
	st.push(6);
	st.push(1);
	st.push(2);
	st.push(0);
	st.push(-1);
	st.push(-11);
	
	goTillEnd();
	cout<<st.size();
	while(!st.empty())
	{
		cout<<st.top()<<endl;
		st.pop();
		
	}
	return 0;
}


// kousick.s@hashedin.com