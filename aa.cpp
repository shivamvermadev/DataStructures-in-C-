#include<bits/stdc++.h>
using namespace std;


// ye waala function ke upar


int f(int x, int *a) {
    if(x ==0) {
        return 0;
    }
    if(x == 1) {
        return 1;
    }
    if(x == 2) {
        return 2;
    }

    // int q1 = INT_MAX;
    // int q2 = INT_MAX;

    // if(!(x&1)) {
    //     q1 = 1 + f(2, a);
    //     q2 = 1 + f(x-1, a);
    //     return min(q1, q2);
    // }


    for(int p=(x/2);p>=1;--p) {
        if((x%p == 0) && (a[p] == 1)) {
            return 1 + f(p, a);
        }
    }
    return 1 + f(x-1, a);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

// ye waala saara funtion k ander likh

	const int n = 10000;

	int *a = new int[n];
	fill(a,a+n,1);
    a[0] = 0;
    a[1] = 0;
    
    for(int i=4;i<n;i+=2) {
        a[i] = 0;
    }   

	for(int i=3;i*i<n;i+=2)
	{
		if(a[i])
		{
			for(int j=i*i;j<n;j+=2*i)
			{
				a[j] = 0;
			}
		}
	}		

    int x = intput1;
    int ans = f(x, a);
    return ans;
}