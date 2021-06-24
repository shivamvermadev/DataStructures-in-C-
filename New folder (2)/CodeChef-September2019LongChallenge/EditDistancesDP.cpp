#include<bits/stdc++.h>
using namespace std;

int f(char a[100],char b[100])
{
	int dp[101][101] = {0};
	int m = strlen(a);
	int n = strlen(b);
	for(int i=1;i<=m;++i)
	{
		dp[0][i] = 1 + dp[0][i-1];
	}
	for(int i=1;i<=n;++i)
	{
		dp[i][0] = 1 + dp[i-1][0];
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			int q1 = dp[i-1][j-1];
			int q2 = dp[i-1][j];
			int q3 = dp[i][j-1];
			dp[i][j] = min(q1, min(q2, q3)) + (a[i-1]!=b[j-1]);
		}
	}
	return dp[m][n];
}



int main()
{
	char input[100],output[100];
	cin>>input>>output;
	int ans = f(input, output);
	cout<<ans<<endl;
}