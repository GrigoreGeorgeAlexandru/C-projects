#include <iostream>
#include <fstream>
using namespace std;

int main()
{int n,m,I;
ifstream f("immortal.in");
ofstream g("immortal.out");
f>>n>>m>>I;
int i,j,tabla[20][20];
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
tabla[i][j]=0;
int k;
for(k=1;k<=I;k++)
{f>>i>>j;
tabla[i][j]=1;

}
//for(i=1;i<=n;i++){for(j=1;j<=m;j++)cout<<tabla[i][j];cout<<endl;}

for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
if(tabla[i][j]==1)
{

}

}
