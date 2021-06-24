//EasyFibonacci
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 1000000009
ll f[1000000];

ll fib(ll n)
{
	if(f[n]!=0)
	{
		return f[n];
	}
	ll k = n/2;
	if(n%2==0)
	{
		return f[n] = (fib(k)*fib(k)+fib(k-1)*fib(k-1))%M;
	}
	else
	{
		return f[n] = (fib(k)*fib(k+1)+fib(k)*fib(k-1))%M;
	}
}

int main()
{
	long n,t;
	f[0] = f[1] = 0;
	f[2]  = 1;
	while(cin>>t)
	{
		cin>>n;
		cout<<fib(n)<<endl;
	}
	return 0;
}