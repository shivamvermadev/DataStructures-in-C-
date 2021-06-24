#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

vector<vector<ll> >  multiply(vector<vector<ll> > a,vector<vector<ll> > b)
{
	vector<vector<ll> > v(2,vector<ll> (2));
	
	for(ll i=0;i<2;++i)
	{
		for(ll j=0;j<2;++j)
		{
			for(ll k=0;k<2;++k)
			{
				v[i][j] += ((a[i][k] * b[k][j])%mod)%mod;
			}
		}
	}
	return v;
}

vector<vector<ll> > f(vector<vector<ll> > a,ll n)
{

	if(n==1)
	{
		return a;
	}

	vector<vector<ll> > v = f(a,n/2);
	v = multiply(v,v);
	if(n&1)
		v = multiply(v,a);

	return v;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll t,n,p;
	cin>>t;
	
	vector<vector<ll> > v(2,vector<ll> (2));
	vector<vector<ll> > m(2,vector<ll> (2));
	m[0][0] = 0;
	m[0][1] = 1;
	m[1][0] = 1;
	m[1][1] = 1;

	while(t--)
	{
		cin>>n>>p;//>>m;
		// if(n==0||n==1)
		// {
		// 	cout<<n<<endl;
		// 	continue;
		// }
		ll ans = 0;
		// if(p==0)
		// {
		// 	cout<<"0"<<endl;
		// 	continue;
		// }
		// else if(n <= 1)
		// {
		// 	ans = 1;
		// 	n = 2;
		// }

		
			v = f(m,p+2);
			ll a = (((v[0][0] * 0) + (v[0][1] * 1))%mod)%mod;
			v = f(m,n+1);
			ll b = (((v[0][0] * 0) + (v[0][1] * 1))%mod)%mod;
			ans = (a%mod -b%mod +mod)%mod;
		cout<<ans<<endl;
	}
	return 0;
}