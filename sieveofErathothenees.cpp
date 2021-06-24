#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,n;
	
	cin>>t>>n;

	int *a = new int[100];
	fill(a,a+n,1);
	
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
    int ptr = 100;
    for(int i = 2; i < me; i ++){
        if(!a[i]){
            if(ptr == 100){
                printf("%d\n", i);
                ptr = 1;
            }
            else ptr ++;
        }
    }
	
	return 0;
}