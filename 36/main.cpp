#include <iostream>
#include <fstream>
using namespace std;

int cifra(int a){
while(a>=0)
{
 if((a%10)%2==0){
  return a%10;
 }
  else if(a>10){
a=a/10;}
else{return -1;}
}
}

int main()
{ifstream f("bac.in");
  int n,i,x,j,S=0,a[10000];f>>n;
  for(i=1;i<=n;i++){
    f>>x;
    a[i]=cifra(x);
  }
  for(i=1;i<=n;i++){
    for(j=i;j<=n;j++){
        if(a[i]<a[j]){
            x=a[i];
            a[i]=a[j];
            a[j]=x;
}
}
}
  for(i=1;i<=n;i++){
        if(a[i]>=0){
    S=S*10+a[i];
  }}
  cout<<S;
}
