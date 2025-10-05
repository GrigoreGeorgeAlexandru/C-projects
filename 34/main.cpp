#include <iostream>

using namespace std;

int main()
{
   int i,j,a[100][100],n,nr=0;
   cin>>n;
   for(i=1;i<=n;i++)
   for(j=1;j<=n;j++){
    nr=nr+2;
    if(nr%3!=0)
    a[i][j]=nr;
    else
    {a[i][j]=nr+2;
    nr=nr+2;}
    }
for(i=1;i<=n;i++){
for(j=1;j<=n;j++)
    cout<<a[i][j]<<" ";
    cout<<endl;}
    return 0;
}
