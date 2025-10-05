#include <iostream>
#include <fstream>
using namespace std;

int cifrak(int n,int k){
int S=0;
while(n>0){
 if(n%10==k){
  S++;
 }
 n=n/10;
}
return S;}
int main(){
ifstream f("numere.txt");
int n;
while(!f.eof()){
  f>>n;
  if(cifrak(n,0)==3)
    cout<<n<<" ";

}
}
