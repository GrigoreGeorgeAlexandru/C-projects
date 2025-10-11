#include <iostream>
#include <fstream>
using namespace std;

int main()
{ifstream f("summaxin.txt");
ofstream g("summaxout.txt");
int v,n,st,dr,a[200][200];
f>>v>>n>>st>>dr;
int i,j;
for(i=1;i<=n;i++)
for(j=1;j<=i;j++)
f>>a[i][j];

/*for(i=1;i<=n;i++)
{for(j=1;j<=i;j++)
cout<<a[i][j];
cout<<endl;
}*/
int valori[200][200]={0};valori[1][1]=a[1][1];
int aux[2]={0};

/*for(i=1;i<=n;i++)
{for(j=1;j<=i;j++)
cout<<valori[i][j];
cout<<endl;
}*/
for(i=2;i<=n;i++)
    for(j=1;j<=i;j++)
{aux[1]=0;aux[2]=0;
    if(valori[i-1][j]&&valori[i][j]<a[i][j]+valori[i-1][j])
    aux[1]=a[i][j]+valori[i-1][j];
    if(valori[i-1][j-1]&&valori[i][j]<a[i][j]+valori[i-1][j-1])
    aux[2]=a[i][j]+valori[i-1][j-1];
    if(aux[1]<aux[2])
        valori[i][j]=aux[2];
    else
        valori[i][j]=aux[1];
}
/*for(i=1;i<=n;i++)
{for(j=1;j<=i;j++)
cout<<valori[i][j]<<" ";
cout<<endl;}*/

int drumuri[200][200]={0};
drumuri[1][1]=1;

for(i=2;i<=n;i++)
    for(j=1;j<=i;j++)
{
    if(valori[i-1][j]&&valori[i][j]==a[i][j]+valori[i-1][j])
    drumuri[i][j]=drumuri[i][j]+drumuri[i-1][j];
    if(valori[i-1][j-1]&&valori[i][j]==a[i][j]+valori[i-1][j-1])
   drumuri[i][j]=drumuri[i][j]+drumuri[i-1][j-1];
}

/*for(i=1;i<=n;i++)
{for(j=1;j<=i;j++)
cout<<drumuri[i][j]<<" ";
cout<<endl;}*/

int maxi=-1,nr=0;
for(i=1;i<=n;i++)
    if(maxi<=valori[n][i])
maxi=valori[n][i];//cout<<maxi;
for(i=1;i<=n;i++)
if(valori[n][i]==maxi)
nr+=drumuri[n][i];
cout<<nr;

int trasee[1000][200];
    for(j=1;j<=n;j++)
if(valori[n][j]==maxi)
if(valori[n][j]==a[n][j]+valori)










}
