#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{ifstream f("permutare.in");
ofstream g("permutare.out");
int n,m,s,mini=0,i,j;
f>>n>>m;int x;
for(i=1;i<=n;i++)
    f>>x;
int a[720][720]={0};
for(i=2;i<=m;i++)
{f>>x;
if(x>n)
    x=n-x;
    a[i][1]=x;
    a[1][i]=a[i][1];}

for(i=2;i<=m;i++)
    for(j=2;j<=m;j++)
    if(i!=j)
    a[i][j]=abs(a[i][1]-a[1][j]);
//for(i=1;i<=m;i++){for(j=1;j<=m;j++)cout<<a[i][j]<<" ";cout<<endl;}
for(i=1;i<=m;i++)
{s=0;
for(j=1;j<=m;j++)
s+=a[i][j];
    if(mini==0)
        mini=s;
    if(mini>s)
       mini=s;
}
g<<mini;


}
