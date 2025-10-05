#include <iostream>
#include <fstream>
using namespace std;

void nule(int a[],int n)
{int i=1,j=n,m;
while(i<j){
  if(a[i]==0){
    if(a[j]!=0){
        m=a[i];
        a[i]=a[j];
        a[j]=m;
}
    else
    j--;
}
  else
    i++;
}
}
int main(){
ifstream f("nr1.txt");
ofstream g("nr2.txt");
int n,m,i,j,a[100];
f>>n>>m;
for(i=1;i<=n;i++){
for(j=1;j<=m;j++)
f>>a[j];
nule(a,m);
for(j=m;j>=1;j--)
 g<<a[j]<<" ";
g<<endl;
}
}
