#include <iostream>

using namespace std;

int main()
{
    int n,m,i,j,A[11][11];
    cin>>n>>m;
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    if(i<j)
    A[i][j]=i;
     else
     A[i][j]=j;
     for(i=1;i<=m;i++){
    for(j=1;j<=n;j++)
    cout<<A[i][j]<<" ";
    cout<<endl;}
    return 0;
}
