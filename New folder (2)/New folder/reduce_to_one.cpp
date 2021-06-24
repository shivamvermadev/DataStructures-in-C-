#include<bits/stdc++.h>
using namespace std;
const int inf = (int) 1e9;

int memo[1000];

int f(int n)
{
	if(memo[n]!=-1)
		return memo[n];

	if(n==1)
		return 0;
	int q1=inf,q2=inf,q3=inf;
	if(n%3==0)
		q1 = 1+f(n/3);
	if(n%2==0)
		q2 = 1+f(n/2);
	q3 = 1+f(n-1);
	return memo[n]=min(q1,min(q2,q3));
}
int main()
{
	fill(memo,memo+1000,-1);
	int n;
	cin>>n;
	int ans = f(n);
	cout<<ans<<endl;
	return 0;

}