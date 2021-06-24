#include<bits/stdc++.h>
using namespace std;
#define int long long int

void insertionSort(int *a, int n) {
    for(int i=1;i<n;++i) {
        int key = a[i];
        int j=i-1;
        while(j >= 0 && key < a[j]) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
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
    insertionSort(a, n);
    for(int i=0;i<n;++i) {
        cout<<a[i]<<" ";
    }
    
    

return 0;
}
// 7300894839