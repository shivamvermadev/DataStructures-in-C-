#include<iostream>
using namespace std;

void sieveOfEratosthenes(int *A,int n)
{
	A[0] = A[1]=0;
	A[2] = 1;
	for(int i=3;i<=n;i=i+2)
	{
		A[i] = 1;
	}
	for(int i=3;i<=n;i=i+2)
	{
		if(A[i])
		{
			for(int j=i+i;j<=n;j+=i)
			{
				A[j]=0;
			}
		}
		
	}

}

int main()
{
	int N=1000000;
	int A[N]= {0};
	int n =100;	
	sieveOfEratosthenes(A,n);
	for(int i=0;i<=n;++i)
	{
		if(A[i]==1)
			cout<<i<<endl;
	}
	return 0;
	
}
