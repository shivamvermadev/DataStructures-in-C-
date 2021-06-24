#include<bits/stdc++.h>
using namespace std;
#define int long long int

int f(int x) {
    if(x == 1 || x == 2) {
        return x;
    }
    return f(x- 1) * f(x-2);
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<f(6);
    
    

return 0;
}



