#include<bits/stdc++.h>
using namespace std;
#define int long long int

void selectionSort(int *a, int n) {
    for(int i=0;i<n-1;++i) {
        int min = i;
        for(int j=i+1;j<n;++j) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[min], a[i]);
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
    selectionSort(a, n);
    for(int i=0;i<n;++i) {
        cout<<a[i]<<" ";
    }
    
    

return 0;
}