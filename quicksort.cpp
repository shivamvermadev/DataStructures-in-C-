#include<bits/stdc++.h>
using namespace std;
#define int long long int

int partition(int *a, int start, int end) {
    int pivot = a[end];
    int pIndex = start;
    for(int i=start;i<end;++i) {
        if(a[i] <= pivot) {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[end], a[pIndex]);
    return pIndex;
}

void quickSort(int *a, int start, int end) {
    if(start < end) {
        int pivot = partition(a, start, end);
        quickSort(a, start, pivot - 1);
        quickSort(a, pivot + 1, end);
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
    quickSort(a, 0, n-1);
    for(int i=0;i<n;++i) {
        cout<<a[i]<<" ";
    }
    

return 0;
}