#include <iostream>

using namespace std;

int prim(int n){       //prim verifica daca un numar e prim
int i,f=1;
for(i=2;i<=n/2;i++){
   if(n%i==0)
   f=0; }
   return f;
}
int i_prim(int n){  //i_prim primeste parametru si  stockeaza valoarea lui in 2 variabile.
    int p1,p2,m;    // pe prima variabila o creste pana devine un nr prim,iar pe a doua o
    m=n;             // scade pana devine nr prim.La final face si afiseaza diferenta celor
    while(!prim(n)){  // 2 nr prime obtinute.
        n++;
    }
p2=n;
while(!prim(m)){
 m--;
}
p1=m;
return p2-p1;
}
int main(){
int n,s;
cin>>n;
s=i_prim(n);
cout<<s;
}
