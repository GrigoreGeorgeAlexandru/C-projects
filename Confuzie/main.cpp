#include <iostream>
#include <fstream>
using namespace std;

int main()
{ifstream f("confuzie.in");
ofstream g("confuzie.out");
int n,m;f>>n>>m;
int tati[200000];tati[1]=1;int culoare[200000]={0};
int i;
for(i=1;i<n;i++)
{int x,y;
f>>x>>y;//cout<<x<<y<<endl;
if(tati[x])
{tati[y]=x;}
else
    {tati[x]=y;}

}tati[1]=0;
//for(i=1;i<=n;i++)cout<<tati[i]<<" ";
for(i=1;i<=m;i++)
{int c;
f>>c;//cout<<"c="<<c<<endl;
if(c==1)
{int u,p;int nod=-1;
f>>p>>u;//cout<<u<<p;
while(tati[u]!=tati[p])
{//cout<<u<<endl;
    if(culoare[u]==1)
nod=u;
u=tati[u];

}
 if(culoare[u]==1)
        nod=u;
 g<<nod<<endl;
}
 else
 {int c;
  f>>c;
  if(culoare[c]==0)
  culoare[c]=1;
  else
    culoare[c]=0;

 }
}


}
