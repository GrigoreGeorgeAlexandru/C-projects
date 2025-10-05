#include <iostream>

using namespace std;

void f(int n,int a[]){
int maxi=0,mini=10000,i;
for(i=1;i<=n;i++){
 if(a[i]<mini && a[i]%2==0)
   mini=a[i];
 if(a[i]>maxi && a[i]%2!=0)
    maxi=a[i];
}
for(i=1;i<=n;i++){
  if(a[i]==mini){
        a[i]=maxi;}
  else
    if(a[i]==maxi){
  a[i]=mini;}
}
}


int main()
{int a[1000],i,n;
cin>>n;
for(i=1;i<=n;i++)
   cin>>a[i];
f(n,a);
for(i=1;i<=n;i++)
    cout<<a[i]<<" ";

}
