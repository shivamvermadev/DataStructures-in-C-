#include<bits/stdc++.h>
using namespace std;
#define ll long long int

map<ll,ll> mr;
map<ll,ll> mc;

int main()
{

	ll t,n,m,q,x,y,count;
	cin>>t;
	while(t--)
	{
		count = 0;
		cin>>n>>m>>q;
		vector<vector<ll> > a(n+1,vector<ll> (m+1));

		while(q--)
		{
			cin>>x>>y;

			mr[x]++;
			mc[y]++;
		}
		
		for(auto T : mr)
		{
			if((T.second)&1)
				count += m;  
		}

		for(auto T : mc)
		{
			if((T.second)&1)
				count += n;
		}
		
		cout<<count<<endl;
		mr.clear(); mc.clear();
	}
}