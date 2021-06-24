#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000000
using namespace std;
ll t,k,num,n;
vector<ll> b,c;

vector<vector<ll> > multiply(vector<vector<ll> > A,vector<vector<ll> > B )
{
	vector<vector<ll> > kk;
	for(int i=0;i<k;++i){
		for(int j=0;j<k;++j){
			for(int x=0;x<k;++x)
			{
				kk[i][j] = (kk[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;
			}
		}
	}
	return kk;

}

vector<vector<ll> > pow(vector<vector<ll> > T, ll p)
{
	if(p==1)
		return T;
	
	if(p&1)
	{
		return multiply(T, pow(T, p-1)); 
	}
	else
	{
		vector<vector<ll> > Z = pow(T, p/2);
		return multiply(Z,Z);
	}	
}


ll compute(ll n)
{
	vector<vector<ll> > T(k,vector<ll>(k));
	for(int i=0;i<k;++i)
	{
		for(int j=0;j<k;++j)
		{
			if(i!=(k-1))
			{
				if(j==(i+1))
					T[i][j] = 1;
				else 
					T[i][j] = 0;				
 			}
 			T[i][j] = c[k-(j+1)];
		}
	}
	
	vector<vector<ll> > Tn = pow(T,n-1);
	
	ll res=0;
	for(int h=0;h<k;++h)
	{
		res = (res + (Tn[0][h]*b[h])%MOD)%MOD;
	}
	return res;
	
}


int main()
{
	cin>>t;
	while(t--)
	{
		cin>>k;

		for(int i=0;i<k;++i)
		{
			cin>>num;
			b.push_back(num);
		}
			for(int i=0;i<k;++i)
		{
			cin>>num;
			b.push_back(num);
		}
		cin>>n;
		cout<<compute(n)<<endl;
		
		
		b.clear();
		c.clear();
		
	}
	return 0;
}

