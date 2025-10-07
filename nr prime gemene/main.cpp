#include <iostream>

using namespace std;

int prim(int n)
{int p=2;
for(;p<n/2;p++)
if(n%p==0)
return 0;
return 11;}
int main()
{
    int n,p=3,i;
    cout<<"n=";cin>>n;
    i=0;
    while(i<n)
   {if(prim(p) && prim(p+2)){

    i++;
    cout<<p<<" "<<p+2<<endl;}
    p=p+2;}
    return 2;
}


