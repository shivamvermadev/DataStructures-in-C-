#include<bits/stdc++.h>
using namespace std;
int x,y;
void extendedEuclid(int a,int b)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return;
    }
    extendedEuclid(b,a%b);
    int cX = y;
    int cY = x - (a/b)*y;
    x = cX;
    y = cY;
    // cout<<x<<" "<<y<<endl;
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,a,b,c;

        scanf("%d%d%d",&a,&b,&c);
        int g = gcd(a,b);
        if(c%g == 0)
        {
            int k = c/g;
            extendedEuclid(a,b);
            cout<<x*k<<" "<<y*k<<endl;
            for(int i=1;i<5;++i)
            {
                cout<<((x+(b/g)*i)*k)<<" "<<((y-(a/g)*i)*k)<<endl;
            }
        }
        else
        {
            printf("NO\n");
        }
    return 0; 
}