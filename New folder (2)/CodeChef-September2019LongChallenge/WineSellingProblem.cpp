#include<bits/stdc++.h>
using namespace std;

// int memo[1000][1000];

// int f(int a[],int start,int end,int year)
// {
// 	if(start>end)
// 		return 0;

// 	if(memo[start][end]!=-1)
// 		return memo[start][end];

// 	int q1 = a[start] * year + f(a, start+1, end, year+1);
// 	int q2 = a[end] * year + f(a, start, end-1, year+1);
// 	int ans = max(q1,q2);
// 	memo[start][end] = ans;
// 	return ans;
// }

int dp[1000][1000];

int wineSellingDP(int a[],int n)
{
	int year = n;
	for(int i=0;i<n;++i)
	{
		dp[i][i] = a[i] * n;
	}
	year--;
	for(int len = 2;len<=n;++len)
	{
		int start = 0;
		int end = n-len;
		while(start <= end)
		{
			int endWindow = start+len-1;

			dp[start][endWindow] = max(a[start] * year + dp[start+1][endWindow], a[endWindow]*year + dp[start][endWindow-1]);
			start ++;
		}
		year--;
	}
	return dp[0][n-1];
}



int main()
{
	memset(memo,-1,sizeof(memo));

	int n;
	int a[1000];
	
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	// int ans = f(a,0,n-1,1);
	int ans = wineSellingDP(a,n);

	cout<<ans<<endl;
}
