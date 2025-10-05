#include <iostream>

using namespace std;
int suma(int v[],int n,int i,int j){
int S=0,x;
for(x=1;x<i;x++){
  S=S+v[x];
}
for(x=j+1;x<=n;x++){
 S=S+v[x];
}
return S;
}



int main()
{

}
