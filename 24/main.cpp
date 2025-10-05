#include <iostream>
#include <iomanip>
using namespace std;

float mini=10000,maxi=0,sum=0;
void p(float n,int x[]){
int i;
for(i=1;i<=n;i++){
if(x[i]<mini){
 mini=x[i];
}
if(x[i]>maxi){
maxi=x[i];
}
sum=sum+x[i];
}
}
int main(){
int x[100],i;float M,n;cin>>n;
for(i=1;i<=n;i++){
  cin>>x[i];
}
p(n,x);
M=(sum-mini-maxi)/(n-2);cout<<fixed<<setprecision(3)<<M;
}
