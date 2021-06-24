#include<bits/stdc++.h>
using namespace std;
#define int long long int

// can work as min/ max heap on changing the sign of conditions in loop
void insert(int *a, int x, int &i, int n) {
    if(i == n) {
        cout<<"overflow"<<endl;
        return;
    }
    int lastPos = -1;
    i++;
    if(i == 0) {
        a[i] = x;
        return;
    }
    lastPos = i;
    a[i] = x;
    int parent_i = (i-1)/2;

    while(i != 0 && a[parent_i] < a[i]) {
        swap(a[parent_i], a[i]);
        i = parent_i;
        parent_i = (i-1)/2;
    }
    i = lastPos;
}

void heapify(int *a, int i, int maxHeapSize) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int pos = -1;
    if(l < maxHeapSize && a[l] > a[r]) {
        pos = l;
    }
    if(r < maxHeapSize && a[r] > a[l]) {
        pos = r;
    }

    if(pos != -1 && a[pos] > a[i]) {
        swap(a[pos], a[i]);
        heapify(a, pos, maxHeapSize);
    }

}
void remove(int *a, int &i) {
    if(i == -1){
        cout<<"UnderFlow"<<endl;
        return;
    }
    if(i == 0) {
        cout<<"Element deleted is "<<a[0]<<endl;
        i--;
        return;
    }

    cout<<"Element deleted is "<<a[0]<<endl;
    swap(a[i], a[0]);
    a[i] = INT_MIN;
    i--;
    heapify(a, 0, i);
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int x;

    cout<<"enter the size "<<endl;
    cin>>n;

    int *a = new int[n]{0};
    int pos = -1;
 
    for(int i=0;i<n;++i) {
        cin>>x;
        insert(a, x, pos, n);       
    }

    for(int i=0;i<n;++i) {
        cout<<a[i]<<" ";
    }   
    cout<<endl;

    remove(a, pos);
    remove(a, pos);
    for(int i=0;i<n;++i) {
        cout<<a[i]<<" ";
    }   
    

return 0;
}

// 50 30 20 15 10 8 16 60