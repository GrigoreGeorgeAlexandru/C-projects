#include <iostream>
#include <fstream>
using namespace std;




int main()
{int n,m=0,coordonate[1000][2],r[70],pozitii[1000],progdin[1000];
//struct cerc{int x,y,r;};cerc x,mat[1000][1000];
ifstream f("cercin.txt");
ofstream g("cercout.txt");
int i,j;
f>>n;for(i=1;i<=n;i++)progdin[i]=1;
for(i=1;i<=n;i++)
{for(j=1;j<=2;j++)
f>>coordonate[i][j];
f>>r[i];
}
//for(i=1;i<=n;i++){for(j=1;j<=2;j++)cout<<coordonate[i][j]<<" ";cout<<r[i]<<" ";cout<<endl;}
for(i=1;i<=n;i++)
{int f=0;
for(j=1;j<i;j++)
 {if(coordonate[i][1]*coordonate[j][2]==coordonate[i][2]*coordonate[j][1])
   {f++;
   pozitii[i]=pozitii[j];
   }
 }//x.x=coordonate[i][1];x.y=coordonate[i][2];x.r=r[i];
 if(f==0){m++;
 //mat[m][1]=x;}else
pozitii[i]=m;}
}
//for(i=1;i<=n;i++)cout<<pozitii[i]<<" ";}
for(i=1;i<n;i++)
    for(j=i+1;j<=n;j++)
    if(pozitii[i]==pozitii[j]&&coordonate[i][1]>coordonate[j][1])
{int aux;
aux=coordonate[i][1];
coordonate[i][1]=coordonate[j][1];
coordonate[j][1]=aux;
aux=coordonate[i][2];
coordonate[i][2]=coordonate[j][2];
coordonate[j][2]=aux;
aux=r[i];
r[i]=r[j];
r[j]=aux;
aux=pozitii[i];
pozitii[i]=pozitii[j];
pozitii[j]=aux;}
progdin[1]=1;
for(i=2;i<=n;i++)
    for(j=1;j<i;j++)
if(pozitii[i]==pozitii[j]&&((coordonate[i][1]-coordonate[j][1])*(coordonate[i][1]-coordonate[j][1])+(coordonate[i][2]-coordonate[j][2])*(coordonate[i][2]-coordonate[j][2]))>=(r[i]+r[j])*(r[i]+r[j])&&progdin[i]<progdin[j]+1)
   progdin[i]=progdin[j]+1;
 //for(i=1;i<=n;i++)cout<<progdin[i]<<" ";
   int q=0;
for(i=1;i<=n;i++)
    if(progdin[i]>q)
    q=progdin[i];
int p=0;
 for(i=1;i<=n;i++)
    if(progdin[i]==q&&pozitii[i]!=pozitii[i+1])
    p++;

    cout<<m<<" "<<q<<" "<<p;
}



