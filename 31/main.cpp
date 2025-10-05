#include <iostream>

using namespace std;
void ordonare(int x[],int n){
int i,j,m;
for(i=1;i<=n;i++){
 if(x[i]%2!=0){
   for(j=i+1;j<=n;j++){
    if(x[j]%2!=0){
      if(x[i]>x[j]){
       m=x[i];
       x[i]=x[j];
       x[j]=m;
       i=i-1;
      }
    }
   }
 }
}



}





int main()
{int x[100],i,n;cin>>n;
for(i=1;i<=n;i++){
    cin>>x[i];
    ordonare(x,n);
}

}
