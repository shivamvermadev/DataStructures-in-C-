#include <bits/stdc++.h>
using namespace std;
#define int long long int

class Solution
{
public:
    vector<string> ans;
    void dfs(int i, int j, vector<vector<int>> &a, int n, string curPath, vector<vector<int>> &visited)
    {
        if (i < 0 || j < 0 || i >= n || j >= n || visited[i][j] == true)
        {
            return;
        }

        if (a[i][j] == 0)
        {
            return;
        }

        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(curPath);
            return;
        }

        visited[i][j] = 1;

        dfs(i, j - 1, a, n, curPath + "L", visited); // left
        dfs(i, j + 1, a, n, curPath + "R", visited); // right
        dfs(i - 1, j, a, n, curPath + "U", visited); // up
        dfs(i + 1, j, a, n, curPath + "D", visited); // down
        visited[i][j] = 0;
    }

    vector<string> findPath(vector<vector<int>> &a, int n)
    {

        if (a[n - 1][n - 1] == 0)
        {
            return {};
        }

        vector<vector<int>> visited(n, vector<int>(n, 0));
        dfs(0, 0, a, n, "", visited);
        return ans;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}