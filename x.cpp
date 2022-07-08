#include<bits/stdc++.h>
using namespace std;
#define int long long int


void dfs(int node, unordered_map<int, list<pair<int, int>>> adjList, vector<bool> &visited, int &count, vector<int> &ans
, int &curDist) {
    visited[node] = true;
    count++;
    if(count == adjList.size()) {
        ans.push_back(curDist);
    }
    
    for(auto x : adjList[node]) {
        pair<int, int> p = x;
        int dest = x.first;
        int weight = x.second;
        if(visited[dest] == false) {
            curDist += weight;
            dfs(dest, adjList, visited, count, ans, curDist);
            curDist -= weight;
        }
    }
    
    visited[node] = false;
    count--;
}

int shortestRoute(vector<vector<int>> &a)
{
    int n = a.size();
	unordered_map<int, list<pair<int, int>>> adjList;
    
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            if(i == j) {
                continue;
            }
            adjList[i].push_back(make_pair(j, a[i][j]));
            adjList[j].push_back(make_pair(i, a[i][j]));
        }
    }
    
    vector<int> ans;
    
    for(int i=0;i<n;++i) {
        int count = 0;
        int curDist = 0;
        vector<bool> visited(n, false);
        
        if(visited[i] == false) {
            dfs(i, adjList, visited, count, ans);
        }
    }
    int minDist = INT_MAX;
    for(auto x : ans) {
        minDist = min(minDist, x);
    }
    return minDist;
}


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    

return 0;
}