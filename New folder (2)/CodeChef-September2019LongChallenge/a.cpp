#include<bits/stdc++.h>
using namespace std;
#define ll long long int

map<ll,ll> freq;

map<char,ll> ascii;

int main()
{
	int h = 10;

	for(int i=65;i<=90;++i)
	{
		ascii[(char)i] =h;
		h++; 
	}

	ll t, n, x, val, outer_flag = 0, value=0,flag = 0;
	string str;
	cin>>t;
	while(t--)
	{
		flag = 0; outer_flag = 0; val = -1;

		cin>>n;
		
		ll **a = new ll*[n];

		for(int i=0;i<n;++i)
		{
			cin>>x>>str;
			int len = str.length();

			a[i] = new ll[(ll)37]{0};

			for(int base = 2;base<=36;++base)
			{
				ll ans = 0;
				for(int k=0;k<str.length();++k)
				{
					if(str[len-k-1]>='A' && str[len-k-1]<='Z')
					{
						ans += ascii[str[len-k-1]] * (pow(base,k));
						continue;
					}
					ans += (str[len-k-1]-'0') * (pow(base,k));
				}
				a[i][base] = ans;
			}
		}
		
		cout<<endl<<endl;
		
		for(int g=0;g<n;++g)
		{
			for(int j=2;j<=36;++j)
			{
				cout<<a[g][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;

		for(int m = 2;m<=36;++m)
		{
			val = a[0][m];
			
			for(int d=2;d<=36;++d)
			{
				if(val==a[1][d])
				{
					 flag = 1; freq[val]++;
					 break;
				}
			}
		}
		
		if(flag == 0)
		{
			cout<<-1;
			continue;
		}
		
		for(auto h:freq)
		{
			val = h.first;
		
			flag = 0;

			for(int i=2;i<n;++i)
			{
				int lb=2, ub=36, mid,flag  = 0;
				
				while(lb<=ub)
				{
					int mid = (ub+lb)/2;

					if(val==a[i][mid])
					{
						flag = 1;
						break;
					}
					else if(val<a[i][mid])
					{
						ub = mid-1;
					}
					else
					{
						lb = mid+1;
					}
				}
				if(flag == 1)
				{
					continue;
				}
				else
				{
					// outer_flag = 1;
					// break;
					continue;
				}
			}
			if(flag == 1)
			{
				cout<<-1<<endl;
				continue;
			}
			else
			{
				cout<<val;
			}
		}
	}
}
