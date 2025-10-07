#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{long n,k,t,i,j,tabla[101][201];
ifstream f("2sah.in");
ofstream g("2sah.out");
f>>t>>n>>k;
if(t==1)
{long long int suma=1;
for(i=1;i<=k-1;i++)
{   suma*=3;
suma%=100003;}
g<<suma;
}
for(i=1;i<=n+1;i++)
for(j=1;j<=2*n+1;j++)
tabla[i][j]=0;
tabla[1][n+1]=1;
for(i=2;i<=n+1;i++)
    for(j=n+2-i;j<=n+i+1;j++)
   {tabla[i][j]+=tabla[i-1][j];
       if(tabla[i-1][j-1])
    tabla[i][j]+=tabla[i-1][j-1];
if(tabla[i-1][j+1])
    tabla[i][j]+=tabla[i-1][j+1];
   }


if(t==2){i=1;int suma=0;
while(i<=n+1&&k<=2*n+1){
suma+=tabla[i][k];
i++;
k+=2;
}
g<<suma;
}
return 0;
}

