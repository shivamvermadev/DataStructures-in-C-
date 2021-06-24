#include<bits/stdc++.h>
using namespace std;
// #define int long long int
map<int,char> m;

int32_t main() 
{
    for(int i=0;i<9;++i){
        m[i] = (char) (48 + i);
    }
        for(int i=0;i<=9;++i){
            cout<<m[i]<<endl;
    }

return 0;
}