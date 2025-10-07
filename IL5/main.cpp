#include <iostream>
#include <fstream>
using namespace std;
void life2(int &a[12][12],&n){
    int i,j,n,c=0,b[12][12];
for(i=1;i<=11;i++)
for(j=1;j<=11;j++)
    b[i][j]=a[i][j];


for(i=1;i<=11;i++){
for(j=1;j<=11;j++){//verifica vecinii
if(a[i-1][j-1]==1)
         c++;
if(a[i-1][j]==1)
         c++;
if(a[i-1][j+1]==1)
         c++;
if(a[i][j-1]==1)
         c++;
if(a[i][j+1]==1)
         c++;
if(a[i+1][j-1]==1)
         c++;
 if(a[i+1][j]==1)
         c++;
if(a[i+1][j+1]==1)
         c++;
if(c==3)        //nastere
b[i][j]=1;
if(c<2||c>3)    //moarte
 b[i][j]=0;
 c=0;
}
}n--;}

int life(int a[12][12]){
    int n,i,j;
    cin>>n;while(n>0)
    life2(a,n);

for(i=1;i<=11;i++){
    for(j=1;j<=11;j++)
        cout<<a[i][j];
        cout<<endl;}
 return life(a);
}


int main()

{ifstream f("date.in");
    int i,j,a[12][12];
    for(i=1;i<=11;i++)
    for(j=1;j<=11;j++)//placa initiala
        a[i][j]=0;

    for(i=4;i<=8;i++)
    for(j=4;j<=8;j++)//sectiune centrala
        f>>a[i][j];

     for(i=1;i<=11;i++){//generatia 0
    for(j=1;j<=11;j++)
        cout<<a[i][j];
        cout<<endl;}
        life(a);

}
