#include<bits/stdc++.h>
using namespace std;
#define int long long int

void merge(int *a, int start, int end) {
    int mid = (start + end)/2;
    int temp[100];
    int k = start;
    int i = start; int j = mid+1;
    while(i <= mid && j <= end) {
        if(a[i] < a[j]) {
            temp[k++] = a[i++];
        }
        else{ 
            temp[k++] = a[j++];
        }
    }
    while(i <= mid) {
        temp[k++] = a[i++];
    }
    while(j <= end) {
        temp[k++] = a[j++];
    }
    for(int i=start;i<=end;++i) {
        a[i] = temp[i];
    }
}

void mergeSort(int *a, int start, int end) {
    if(start < end) {
        int mid = (start + end)/2;
        mergeSort(a, start, mid);
        mergeSort(a, mid+1, end);
        merge(a, start, end);
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
    mergeSort(a, 0, n-1);
    for(int i=0;i<n;++i) {
        cout<<a[i]<<" ";
    }
return 0;
}
