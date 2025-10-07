#include <iostream>
#include <fstream>
using namespace std;
void inter(int &x,int &y){
int m;
m=x;
x=y;
y=m;}

int main()
{ifstream f("bac.in");
int n,i,j,a[10000];
f>>n;
for(i=1;i<=n;i++){
    f>>a[i];
}for(i=1;i<=n;i++){
for(j=i;j<=n;j++){
    if(a[i]>a[j]){
       inter(a[i],a[j]);
    }
}}
for(i=1;i<=n;i++){
cout<<a[i]<<" ";

}
}

