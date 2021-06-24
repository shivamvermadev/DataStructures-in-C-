#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int grid[100][100];
int main()
{
	int r,c;
	memset(dp,-1,sizeof(dp));
	cin>>r>>c;
	for(int i=0;i<r;++i)
	{
		for(int j=0;j<c;++j)
		{
			cin>>grid[i][j];
		}
	}

	dp[0][0] = grid[0][0];
	for(int i=1;i<c;++i)
	{
		dp[0][i] = dp[0][i-1]+grid[0][i];
	}
	for(int i=1;i<r;++i)
	{
		dp[i][0] = dp[i-1][0]+grid[i][0];
	}
	for(int i=1;i<r;++i)
	{
		for(int j=1;j<c;++j)
		{
			dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
		}
	}

	cout<<"MAtrix is as"<<endl;
	for(int i=0;i<r;++i)
	{
		for(int j=0;j<c;++j)
		{
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	cout<<"DP table is as"<<endl;
	for(int i=0;i<r;++i)
	{
		for(int j=0;j<c;++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	cout<<dp[r-1][c-1];
	return 0;
}