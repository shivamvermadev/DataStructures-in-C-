#include<bits/stdc++.h>
using namespace std;

int memo[100];

//memoisation
int f(int a[],int totalLen)
{
	int best = 0;
	if(totalLen == 0)
		return 0;
	
	if(memo[totalLen]!=-1)
		return memo[totalLen];

	for(int len = 1;len<=totalLen;++len)
	{
		int netProfit = a[len] + f(a,totalLen-len);
		best = max(best,netProfit); 
	}
	memo[totalLen] = best;
	return best;
}

//Bottom Up

int rodCuttingBottomUP(int a[],int totalLen)
{
	int dp[100] = {0};

	for(int len = 1; len<=totalLen; ++len)
	{
		int best = 0;
		for(int cut = 1;cut<=len;++cut)
		{
			best = max(a[cut],dp[len-cut]);
		}
		dp[len] = best;
	}
	return dp[totalLen];
}
int main()
{

	int totalLen,a[100];
	cin>>totalLen;

	// fill(memo,memo+totalLen+2,-1);

	for(int i=1;i<=totalLen;++i)
	{
		cin>>a[i];
	}
	// int ans = f(a,totalLen);
	int ans = rodCuttingBottomUP(a,totalLen);
	cout<<ans<<endl;
}