#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Solution
{
    public:
    int numberOfVertices;
    int ans = false;
    
    void dfs(int node, unordered_map<int, list<int>> &adjList, vector<bool> &visited, int src, int &count) {
        visited[node] = true;
        count++;
        
        if(count == numberOfVertices) {
            int flag = 0;
            for(auto k : adjList[node]) {
                if(k == src) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                this->ans = true;
            }
        }
        
        for(auto x : adjList[node]) {
            if(visited[x] == false) {
                dfs(x, adjList, visited, src, count);
            }
        }
        
        count--;
        visited[node] = false;
    }
    
    
    bool check(int v,int e,vector<vector<int>> edges)
    {
        this->numberOfVertices = v;
        unordered_map<int, list<int>> adjList;
        
        for(int i=0;i<e;++i) {
            int src = edges[i][0];
            int dest = edges[i][1];
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
        
        vector<bool> visited(v+1, false);
        
        for(int i=1;i<=v;++i) {
            int count = 0;
            if(visited[i] == false) {
                dfs(i, adjList, visited, i, count);
            }
        }
        
        return ans;
    }
};

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    Solution s;
    // s.check();
    

return 0;
}