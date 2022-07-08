#include<bits/stdc++.h>
using namespace std;

int f(int mask, int pos, vector<vector<int>> &a, vector<vector<int>> &dp, int &visited_all) {
    if(visited_all == mask) {
        return a[pos][0];
    }
    
    if(dp[pos][mask] != -1) {
        return dp[pos][mask];
    }
    int ans = INT_MAX;
    
    for(int city=0;city<a.size();++city) {
        if((mask&(1<<city)) == 0) {
            int curAns = a[pos][city] + f((mask|(1<<city)), city, a, dp, visited_all);
            ans = min(ans ,curAns);        
        }
    }
    return dp[pos][mask] = ans;
}

int shortestRoute(vector<vector<int>> &a)
{
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(1<<n, -1));
    int visited_all = (1<<n) - 1;
    return f(1, 0, a, dp, visited_all);
}
