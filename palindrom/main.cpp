#include <iostream>

using namespace std;

int pal(int n)

{
    int nr=0,p=1,s;
    while(n>0)
    {
        nr=nr+1;
        n=n/10;
    }
    s=nr;
    while(nr>s/2)

 {

if(n/(10^(nr-1))==n%(10*p))
    {
        nr=nr-1;
        p=p+1;}
else
        return -1;

return s;}}


int main()
{int n,i,a[100],s,smax=0;
cin>>n;
for(i=1;i<=n;i++)
{cin>>a[i];
s=pal(a[i]);
if(s>smax)
  smax=s;
}
for(i=1;i<=n;i++)
{s=pal(a[i]);
if(s!=smax)
 cout<<a[i]<<" ";
}
}
