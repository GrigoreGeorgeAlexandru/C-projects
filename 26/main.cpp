#include <iostream>
#include <fstream>
using namespace std;


void sterge(int v[],int &n,int i){
int j;
for(j=i;j<=n;j++){
    v[j]=v[j+1];
}
    n=n-1;
}





int main(){
ifstream f("NUMEREIN.txt");
ofstream g("NUMEREOUT.txt");
int n,v[10000],i;
f>>n;
for(i=1;i<=n;i++)
    f>>v[i];
for(i=1;i<=n;i++){
  if(v[i]==v[i+1])
    {sterge(v,n,i);i--;}
}
for(i=1;i<=n;i++)
    g<<v[i]<<" ";


}
