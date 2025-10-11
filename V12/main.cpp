#include <iostream>

using namespace std;

int main()
{
int n,i,j,a[51][51];
cin>>n;
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(i+j==n+1)
{a[i][j]=0;}
else
if(i+j<n+1)
{a[i][j]=i;}
else
if(i+j>n+1)
{a[i][j]=n-j+1;}
for(i=1;i<=n;i++){
for(j=1;j<=n;j++)
 cout<<a[i][j]<<" ";
cout<<endl;}
    return 0;
}
