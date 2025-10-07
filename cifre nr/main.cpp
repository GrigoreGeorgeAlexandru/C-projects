#include <iostream>
using namespace std;

int p1(int n) { //randul asta e antetul p1
int S=0;
while(n>0)
{
  S=S+n%10;
  n=n/10;
}return S;
}
int p2(int n){ //randul asta e antetul p2
n=n/10;
return n;
}
int main(){
int n,s1,s2,n2,S=0;
cin>>n;
while(n>0){
s1=p1(n); //aici am facut suma cifrelor numarului initial si suma cifrelor numarului dupa ce
n2=p2(n);  // p2 a eliminat ultima cifra.Daca cele 2 sume sunt egale,inseamna ca cifra eliminata
s2=p1(n2);  // este 0,programul o numara in S,si apoi foloseste numarul creat de p2 ca noul nr initial
if(s1==s2)  // si continua sa compare sumele cifrelor pana cand elimina toate cifrele.
{S=S+1;}
n=n2;
}
cout<<S;
}
