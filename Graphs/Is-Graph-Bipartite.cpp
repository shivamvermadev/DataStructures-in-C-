#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Solution {
public:
    bool isBipartite(vector<vector<int>>& a) {
        int V = a.size();
        
        int *color = new int[V];
        for(int i=0;i<V;++i) {
            color[i] = -1;
        }
        
        bool ans = true;
        queue<int> q;
        
        for(int i=0;i<V;++i) {
            if(color[i] != -1) {
                continue;
            }
            
            color[i] = 0;
            q.push(i);
        
            while(q.empty() == false) {
                int node = q.front();
                q.pop();

                for(auto neighbour : a[node]) {
                    if(color[neighbour] == -1) {
                        color[neighbour] = 1 - color[node];
                        q.push(neighbour);
                    }
                    else if(color[neighbour] == color[node]) {
                        ans = false;
                        break;
                    }
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