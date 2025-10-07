#include <iostream>
#include <fstream>
using namespace std;

int main()
{int A[30][30],T[100][100],K,N,M;
ifstream f("expeditiein.txt");
f>>N>>M>>K;
int i,j;
for(i=1;i<=N;i++)
for(j=1;j<=M;j++)
   f>>A[i][j];
  /* for(i=1;i<=N;i++)
{for(j=1;j<=M;j++)
    cout<<A[i][j]<<" ";
cout<<endl;}*/

for(i=1;i<=N;i++)
for(j=1;j<=M;j++)
   f>>T[i][j];
/*for(i=1;i<=N;i++)
{for(j=1;j<=M;j++)
    cout<<T[i][j]<<" ";
cout<<endl;}*/
int timp[100][100];
for(i=1;i<=N;i++)
for(j=1;j<=M;j++)
timp[i][j]=101;
timp[1][1]=0;
for(i=1;i<=N;i++)
for(j=1;j<=M;j++)
{if(timp[i][j]+T[i][j+1]<timp[i][j+1])
timp[i][j+1]= timp[i][j]+T[i][j+1];
   if(timp[i][j]+T[i+1][j+1]<timp[i+1][j+1])
timp[i+1][j+1]= timp[i][j]+T[i+1][j+1];
if(timp[i][j]+T[i+1][j]<timp[i+1][j])
timp[i+1][j]= timp[i][j]+T[i+1][j];
}

for(i=1;i<=N;i++)
{for(j=1;j<=M;j++)
    cout<<timp[i][j]<<" ";
cout<<endl;}



return 0;

}
