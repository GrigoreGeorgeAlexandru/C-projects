#include <iostream>
#include <fstream>
using namespace std;

void P(int &n,int c){
int nr=0,i=1;
while(n>0)
{if(n%10!=c){
nr=nr+n%10*i;
i=i*10;
}
  n=n/10;
}n=nr;}
int main(){
ifstream f("BAC.IN");
ofstream g("BAC.OUT");
int n,i;
while(!f.eof()){
    f>>n;
    for(i=1;i<10;i=i+2)
        P(n,i);
        if(n>0)
        g<<n<<" ";
}}
