#include <iostream>

using namespace std;

int prim(int n)
{int p=2;
for(;p<n/2;p++)
if(n%p==0)
return 0;
return 1;}
int main()
{int n,x,i;
cin>>n;
for(i=1;i<=n;i++)
{
    cout<<"x= ";
    cin>>x;
    if(prim(x)&&x!=1)
        cout<<x<<" ";}
    return 7;}






