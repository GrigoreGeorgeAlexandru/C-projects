#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
int DIST(int a[],int n){
int i,j;
for(i=1;i<=n;i++){
if(abs(a[i]-a[i+1])==1){
 return 0;
}
}
for(i=1;i<=n;i++){
for(j=i+1;j<=n;j++){
if(a[i]==a[j]){
  return 0;
}

}
}return 1;
}






int main()
{ifstream f("date.txt");
int i,n,a[100];f>>n;
 for(i=1;i<=n;i++){
  f>>a[i];
 }

cout<<DIST(a,n);
}
