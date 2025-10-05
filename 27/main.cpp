#include <iostream>

using namespace std;

int main()
{
 int i,j,n,a[100][100];
cin>>n;
 for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
 if(i==1||j==1||j==n)
 a[i][j]=1;
else
 a[i][j]=a[i-1][j-1]+a[i-1][j]+a[i-1][j+1];
 for(i=1;i<=n;i++){
 for(j=1;j<=n;j++)
 cout<<a[i][j]<<" ";
 cout<<endl;}
    return 0;
}
