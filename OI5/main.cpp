#include <iostream>
#include<fstream>
using namespace std;

int main()
{ifstream f("biperm.in.txt");
int n,p1[20],p2[20],numar[20]={0},schimb[20]={0},nr=1,aux,nrbi=0,l=0;
f>>n;int i,j,k;
for(i=1;i<=n;i++)
f>>p1[i];

for(i=1;i<=n;i++)
f>>p2[i];
for(i=1;i<=n;i++)
 {numar[p1[i]]++;}
 for(k=1;k<=n;k++)
while(numar[k]!=1){
for(i=1;i<=n;i++)
 numar[i]=0;
for(i=1;i<=n;i++)
 {
     numar[p1[i]]++;}for(i=1;i<=n;i++)//cout<<numar[i]<<" ";cout<<"*";for(i=1;i<=n;i++)cout<<p1[i]<<" ";cout<<"/";
for(i=1;i<=n;i++)
if(numar[i]!=1)
{for(j=1;j<=n;j++)
if(p1[j]==i&&schimb[j]==0)
{schimb[j]=1;
    aux=p1[j];
p1[j]=p2[j];
p2[j]=aux;break;}
}nr++;}
for(i=1;i<=n;i++)
if(p1[i]!=p2[i])
  nrbi=2;
  for(i=1;i<n;i++)
  for(j=i+1;j<=n;j++)
    if(p1[i]!=p2[i]&&p1[j]!=p2[j]&&p1[i]!=p2[j])
    l=1;
for(i=1;i<n;i++)
for(j=i+1;j<=n;j++)
if(p1[i]==p2[j]&&p1[j]==p2[i]&&l==1)
nrbi=nrbi*2;
for(i=1;i<=n;i++)cout<<p1[i];cout<<endl;for(i=1;i<=n;i++)cout<<p2[i];cout<<" nr bipermutari="<<nrbi;
}
