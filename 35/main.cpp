#include <iostream>

using namespace std;

int sum(int x){
int i,S=0;
for(i=2;i<x;i++){
 if(x%i==0){
  S=S+i;
 }

} return S;
}



int main()
{int n,x,i,j,m,a[1000];
cin>>n;
for(i=1;i<=n;i++){
 cin>>x;
 a[i]=sum(x);
}
for(i=1;i<=n;i++){
for(j=i;j<=n;j++){
 if(a[i]>a[j]){
    m=a[i];
    a[i]=a[j];
    a[j]=m;
 }
}
}
for(i=1;i<=n;i++){
 cout<<a[i]<<" ";
}

}


