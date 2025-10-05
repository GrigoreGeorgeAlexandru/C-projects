#include <iostream>
#include <fstream>
using namespace std;
int suma(int A[],int i,int j){int a,S=0;
for(a=i;a<=j;a++){
   S=S+A[a];
}return S;
}



int main()
{ ifstream f("NUMERE.IN");
ofstream g("NUMERE.OUT");int n,m,i,A[100],B[100],j,a=1;
f>>n>>m;
for(i=1;i<=n;i++){
    f>>A[i];
}
for(i=1;i<=m;i++){
   f>>B[i];
}i=1;
for(j=1;j<=n;j++){
  if(suma(A,i,j)==B[a]){
    i=j+1;
    a=a+1;
  }
}
if(a==m+1){
    g<<"DA";
}
else{
g<<"NU";
}
}


