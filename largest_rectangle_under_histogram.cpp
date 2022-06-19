#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        
        int n = a.size();
        
        int *r = new int[n]{0}; // next smaller element index on right;
        int *l = new int[n]{0}; // next smaller element index on left;
        r[n-1] = n;
        
        stack<int> s;
        s.push(n-1);
    
        for(int i=n-2;i>=0;--i) {
            while(s.empty() == false && a[i] <= a[s.top()]) {
                s.pop();
            }           
            
            if(s.empty() == true) {
                r[i] = n;
            }
            else {
                r[i] = s.top();
            }
            s.push(i);
        }
        
        while(s.empty() == false) {
            s.pop();
        }
        
        s.push(0);
        l[0] = -1;
        
        for(int i=1;i<n;++i) {
            while(s.empty() == false && a[i] <= a[s.top()]) {
                s.pop();
            }
            if(s.empty() == true) {
                l[i] = -1;
            }
            else {
                l[i] = s.top();
            }
            s.push(i);
        }
        
        
        int ans = 0;
        for(int i=0;i<n;++i) {
            int x = (r[i] - l[i] - 1) * a[i];
            ans = max(ans, x);
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