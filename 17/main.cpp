#include <iostream>

using namespace std;

int interval(int a[],int n){
int S=0,i;
for(i=1;i<=n;i++){
if((a[1]<=a[i]&&a[n]>=a[i])||(a[1]>=a[i] && a[n]<=a[i]))
      {S++;}
}
return S;
}
int main(){
int n,a[100],i,S;
cin>>n;
for(i=1;i<=n;i++)
    cin>>a[i];
S=interval(a,n);
cout<<S;}
