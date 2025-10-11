#include <iostream>

using namespace std;

void s1(int &a,int &b){
int m;
m=a;
a=b;
b=m;
}
int s2(int a[100],int p,int q)
{
    int i;
    for(i=p;i<=q;i++)
    {
        if(a[i]%5==0)
            return i;
    }
    return -1;
}
int main(){
int n,a[100],i,Min=10000,Max=0,s;
cin>>n;
for(i=1;i<=n;i++)
{cin>>a[i];

}
for(i=1;i<=n;i++)
{s=s2(a,i,n);
if(s>-1&&s<Min)
   Min=s;
if(s>-1&&s>Max)
    Max=s;
}
s1(a[Max],a[Min]);
for(i=1;i<=n;i++)
    cout<<a[i]<<" ";}
