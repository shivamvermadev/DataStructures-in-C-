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
	int *a = new int[n]{0};
	for(int i=0;i<n;++i) {
		cin>>a[i];
	}

	int H1 = INT_MIN, H2 = INT_MIN;

	for(int i=0;i<n;++i) {
		if(a[i] >= H1) {
			H2 = H1;
			H1 = a[i];
		}
		else{
			H2 = max(H2, a[i]);
		}
	}
	cout<<H1<<" "<<H2<<endl;

return 0;
}
