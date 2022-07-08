#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Solution
{
	public:
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        // pair<int, int> = weight, src
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // sorts by first value in pair greater<pair<int, int>>
        
        bool *visited = new bool[V]{0};
        
        int ans = 0;
        pq.push({0, 0});
        
        while(pq.empty() == false) {
            auto temp = pq.top();
            pq.pop();
            
            int src = temp.second;
            int weight = temp.first;
            
            if(visited[src]) {
                continue;
            }
            
            ans += weight;
            visited[src] = true;
            
            for(auto x : adj[src]) {
                int dest = x[0];
                int w = x[1];
                if(!visited[dest]) {
                    pq.push({w, dest});
                }
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
    
    
    

return 0;
}