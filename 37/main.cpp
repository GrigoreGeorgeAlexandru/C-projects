#include <iostream>
#include <fstream>
using namespace std;

int nrdiv(int x){
int i=2,S=0;
while(x>1){
   if(x%i==0){
    S++;while(x%i==0){

x=x/i;}
   }
i++;


}
return S;

}


int main()
{int i,x,n;ifstream f("bacin.txt");
f>>n;
for(i=1;i<=n;i++){
    f>>x;
    cout<<nrdiv(x)<<" ";
}

}
