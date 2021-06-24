#include<iostream>
using namespace std;

void findUniqueNo(int *a, int n)
{
	int b[64] ={0},k;
	for(int i=0;i<n;++i)
	{
		k = a[i];
		int j=0;
		while(k)
		{
			b[j]+=(k&1);
			k= k>>1;
			++j;
		}
	}
	int ans = 0,p=0;
	for(int s=0;s<64;++s)
	{
		b[s] %=3;
		ans +=b[s]*(1<<p);
		p++;
		
	}
	cout<<ans;
}


int main()
{
	int a[] = {7,7,3,4,12,4,3,3,4,7};
	
	int l = sizeof(a)/sizeof(int);
	findUniqueNo(a,l);
	return 0;		
}

