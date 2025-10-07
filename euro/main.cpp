#include <iostream>
#include <fstream>
using namespace std;

int main()
{ifstream f("euro.in");
ofstream g("euro.out");
int t,n,vmax;
f>>t;
int i,j,jucatori[4000];
for(i=1;i<=t;i++)
{f>>n>>vmax;
    for(j=1;j<=n;j++)
    f>>jucatori[j];
     //for(j=1;j<=n;j++)cout<<jucatori[j]<<" ";cout<<endl;

for(j=1;j<=vmax;j++)
{int p=0,u,k,s=0,v;v=j;int flag=0;
for(k=1;k<=n;k++)
   {if(jucatori[k]>v)continue;
if(jucatori[k]==v){cout<<v<<" ";flag=-1;g<<"0"<<" ";break;}
if(jucatori[k]<v){flag=1;if(s+v<=vmax)s+=v;else break;if(p==0)p=v;u=v;}
   }
if(flag==0){g<<"-1"<<" ";}
if(flag==1){g<<max(u,p)-min(u,p)<<" ";}
}


g<<endl;
}




}
