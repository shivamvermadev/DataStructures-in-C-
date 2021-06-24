#include<bits/stdc++.h>
using namespace std;
#define int long long int


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int *a= new int[n]{0};

    for(int i=0;i<n;++i) {
        cin>>a[i];
    }
    int x = 1, res = 0;

    for(int i=0;i<64;++i) {
         x = (1<<i);
         int sum = 0;
         for(int j=0;j<n;++j) {
             if(a[j]&x) {
                 sum++;
             }
         }
         cout<<"sum " <<sum<<" "<<i<<"\n"; 
         if(sum % 3 != 0 ) {
             cout<<x << " ";
             cout<<"\n";
             res = (res + x);
         }
    }
    cout<<"\n"<<res;

    cout<<(1<<31);

return 0;
}