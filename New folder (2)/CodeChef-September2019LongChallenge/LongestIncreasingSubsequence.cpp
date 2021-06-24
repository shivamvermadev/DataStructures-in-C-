#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ll t,n,k,c_,a_,b_;
	
	cin>>t;
	while(t--)
	{

		cin>>n>>k;

		ll *A = new ll[n]{0};
		
		for(ll i=0;i<n;++i)
		{
			cin>>A[i];
		}
		ll x = k/n;
		ll r = k%n;
		ll r1;

		if(x%3==0)
		{
			r1 = 0;
			for(int i=0;i<n;++i)
			{
				cout<<a[i]<<" ";
			}
			cout<<endl;
			continue;
		}
		else
		{
			r1 = x%3;		
			for(ll i=1;i<=r1;++i)
			{
				for(ll p=0;p<n;++p)
				{
					A[p] = (A[p])^(A[n-1-p]);
					// A[n-1-p] = (A[p])^(A[n-1-p]);
				}	
			}
			for(ll p=0;p<r;++p)
			{
				A[p] = (A[p])^(A[n-1-p]);
				// A[n-1-p] = (A[p])^(A[n-1-p]);
			}
			for(int i=0;i<n;++i)
			{
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
	}
}