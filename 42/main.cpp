#include <iostream>

using namespace std;
int P(int a[],int n, int k){
int i,j,S=0,m;
for(i=1;i<=n;i++){
for(j=i;j<=n;j++){
 if(a[i]<a[j]){
  m=a[i];
  a[i]=a[j];
  a[j]=m;
}
}
}
for(i=1;i<=k;i++){
S=S+a[i];
}return S;
}





int main()
{int n,a[100],i,k;
cin>>n>>k;
for(i=1;i<=n;i++){
 cin>>a[i];
}
cout<<P(a,n,k);
}
