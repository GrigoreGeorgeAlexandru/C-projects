#include <iostream>
#include <fstream>
using namespace std;

int main()
{ifstream f("suma5.in");
int n,c[57][57][57];
f>>n;
int S=0;
int i;
for(i=1;i<=n;i++)
  {S=i*(i+1)*(2*i+1)/6;
  if(S==n)break;
  }
int m=i;
cout<<m;
int j,k;
for(i=1;i<=m;i++)
    for(j=1;j<=m;j++)
    for(k=1;k<=m;k++)
    f>>c[i][j][k];
int piramida[57][57][57];
for(i=1;i<=m;i++)
    for(j=1;j<=m;j++)
    for(k=1;k<=m;k++)
    piramida[i][j][k]=100;
piramida[1][1][1]=c[1][1][1];
for(i=2;i<=m;i++)
    for(j=1;j<=m;j++)
    for(k=1;k<=m;k++)
    {if()

    }
}
