#include <iostream>
#include <fstream>
using namespace std;

int main()

{float a[100];
ifstream f("numere.txt");
    int g,j,n,i;
f>>n;
for(i=1;i<=n;i++){
f>>a[i];

}

for(i=1;i<=n;i++){g=0;
for(j=1;j<=n;j++){
 if(a[i]==a[j]&&i!=j){
  g=1;
 }
}if(g==0){
cout<<a[i]<<" ";}
}
}
