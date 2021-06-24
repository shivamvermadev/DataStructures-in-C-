#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];

int maxProfit(int *arr,int beg,int end, int year)
{
	if(beg>end)
		return 0;
	if(dp[beg][end] != -1)
		return dp[beg][end];

	int q1 = arr[beg] * year + maxProfit(arr,beg+1,end,year+1);
	int q2 = arr[end] * year + maxProfit(arr,beg,end-1,year+1);
	int ans = max(q1,q2);
	return dp[beg][end] = ans;
}
int main(int argc, char const *argv[])
{
	int n, arr[50]={0},year;
	
	cin>>n;
	
	memset(dp,-1,sizeof(dp));
	
	for(int i=0;i<n;++i)
	{
		cin>>arr[i];
	}
	
	year = n;

	for(int i=0;i<n;++i)
	{
		dp[i][i] = year * arr[i];
	}
	
	year--;

	for(int len=2;len<=n;++len)
	{
		int start = 0;
		int end = n-len;

		while(start<=end)
		{
			int endWindow = start+len-1;
			dp[start][endWindow] = max(arr[start] * year + dp[start+1][endWindow], arr[endWindow] * year + dp[start][endWindow-1]);
			start++;
		}
		year--;
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			cout<<setw(3)<<fixed<<dp[i][j];
		}
		cout<<endl;
	}
	cout<<dp[0][n-1]<<endl;
	

	return 0;
}