#include<bits/stdc++.h>
using namespace std;
#define int long long int

void bubbleSort(int *a, int n) {
    for(int i=0;i<n-1;++i) {
        for(int j=0;j<n-i-1;++j) {
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cout<<"Enter the number of elements in an array "<<endl;
    cin>>n;
    int *a = new int[n]{0};
    for(int i=0;i<n;++i) {
        cin>>a[i];
    }
    bubbleSort(a, n);
    for(int i=0;i<n;++i) {
        cout<<a[i]<<" ";
    }
return 0;
}