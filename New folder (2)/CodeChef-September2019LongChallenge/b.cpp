#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll,ll> m;

int main()
{
	ll t,n,c,count,k,i,j,flag;
	cin>>t;
	
	while(t--)
	{
		count = c = 0;
		cin>>n;

		ll *a = new ll[n]{0};
		
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
		}

		for(i=n-1;i>0;i--)
		{
			c = 0;
			flag = 0;

			for(auto T:m)
			{
				if(a[i] % T.first==0)
				{
					flag = 1;
					break;
				}
			}

			if(flag == 1)
			{
				// m[a[i]]++;				
				// continue;
				break;
			}

			m[a[i]]++;

			for(j = i-1;j>=0;j--)
			{
				if(a[j] % a[i]==0)
					c++;
			}
			
			count = max(c,count);

			if(count>=n/2||count>=i)
			{
				break;
			}
		}
		cout<<count<<endl;
		m.clear();
	}
}