#include<bits/stdc++.h>
using namespace std;

void f(int n,int beg,int aux,int end)
{
    if(n==1)
    {

        cout<<"move disk "<<1<<" from rod "<<beg<<" to rod "<<end<<endl;

        return;
    }

    f(n-1,beg,end,aux);
    cout<<"move disk "<<n<<" from rod "<<beg<<" to rod "<<end<<endl;
    f(n-1,aux,beg,end);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        f(n,1,2,3);
    }
}
