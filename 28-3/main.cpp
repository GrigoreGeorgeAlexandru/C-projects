#include <iostream>
#include <fstream>
using namespace std;

int primul(int a){
int i;
for(i=2;i<=a;i++){
    if(a%i==0){
        return i;
    }
}
}





int main()
{ifstream f("NUMEREIN.txt");
ofstream g("NUMEREOUT.txt");
int n,a[100],i,x,y;
f>>n;
for(i=1;i<=n;i++){
    f>>a[i];
}
for(i=1;i<=n;i++){
 x=primul(a[i]);
 y=primul(a[i]/x);
 if(x*y==a[i]&&x!=y){
    g<<a[i]<<" ";
 }
}


}
