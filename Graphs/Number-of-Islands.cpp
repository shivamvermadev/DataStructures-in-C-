#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Solution {
public:
    
    void dfs(int i, int j, vector<vector<char>> &a, int visited[][301]) {
        
        if(i < 0 || j < 0 || i >= a.size() || j >= a[0].size()) {
            return;
        }
        
        if(a[i][j] == '0' || visited[i][j] == 1) {
            return;
        }
        
        visited[i][j] = 1;
        
        dfs(i-1, j, a, visited);
        dfs(i, j+1, a, visited);
        dfs(i, j-1, a, visited);
        dfs(i+1, j, a, visited);
    }
    
    int numIslands(vector<vector<char>>& a) {
        int m = a.size();
        int n = a[0].size();
        
        int visited[301][301] = {0};
        int c = 0;
        
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j)     {
                if(a[i][j] == '1' && visited[i][j] == 0) {
                    c++;
                    dfs(i, j, a, visited);
                }
            }
        }
        return c;
    }
};

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    

return 0;
}