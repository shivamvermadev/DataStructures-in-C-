#include<iostream>
using namespace std;

void isprime(int n)
{
	if(n==1)
	{
		cout<<"not prime"<<endl;
		return;
	}
	else if(n==2)
	{
		cout<<"prime"<<endl;
		return;
	}
	else{
	
	for(int i=2;i*i<=n;++i)
	{
		if(n%i==0)
		{
			cout<<"not prime"<<endl;
			return;
		}
		
	}
	cout<<"prime"<<endl;
}
	
}
int main()
{
	isprime(2);
	isprime(23);
	isprime(24);
	isprime(35);
//	cout<<"hell";
	return 0;	
}
