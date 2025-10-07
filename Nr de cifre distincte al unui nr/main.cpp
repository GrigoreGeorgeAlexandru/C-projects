#include <iostream>

using namespace std;

int nr(int n,int c){ //antentul subprogramului nr
int S=0;
while(n>0)
{
if(n%10==c)
 S=S+1;
n=n/10;
}
return S;}
int main(){
int n,i,S,c=0;
cin>>n;
for(i=0;i<10;i++){   //i o sa ia pe rand valori de la 0 la 9,deci toate cifrele,si
   S=nr(n,i);        // folosind subprogramul nr sa verifice daca numarul n contine fiecare din
   if(S!=0)          //acele cifre.Daca valoarea lui S obtinuta din nr este diferita de 0,adica daca
    c=c+1;           //numarul initial contine cifra verificata de nr,programul va creste valoarea
}                    //lui c cu 1,deci pentru fiecare cifra distincta a numarului initial numarul de
cout<<c;}            //  cifre distincte,c, va creste cu 1.In final programul va afisa valoarea lui c
