#include <iostream>
#include <fstream>
using namespace std;

void aranjare(int a[],int n){
int i=1,j=n,m;
while(i<j){

    if(a[i]>=0){
     if(a[j]<0){
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
int main()
{ ifstream f("nrl.txt");
ofstream g("nrl2.txt");
int n,m,a[100],i,j;
f>>n>>m;
for(j=1;j<=n;j++){
for(i=1;i<=m;i++)
    f>>a[i];
   aranjare(a,m);
for(i=m;i>=1;i--)
    g<<a[i]<<" ";
    g<<endl;}

