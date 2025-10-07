#include <iostream>

using namespace std;
int pr(int x){
int i;
for(i=2;i<x;i++){
if(x%i==0)
    return 0;
}
return 1;
}
int sdiv(int y){
int S=0,i;
for(i=1;i<=y;i++){
 if(y%i==0){
   S=S+i;
 }
}return S;
}


int main()
{int n,i;
cin>>n;
for(i=2;i<n;i++){
  if(pr(sdiv(i))){
     cout<<i<<" ";}
}

}
