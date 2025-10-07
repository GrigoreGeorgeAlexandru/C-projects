#include <iostream>
#include <fstream>
using namespace std;

int main()
{ifstream f("date.in");
ofstream g("date.out");
    int m,j,S=0,nr=1,i,n,mini,maxi;
    f>>n>>mini>>maxi;
    m=n;
    while(m>0){
        nr=nr*10;
        m=m/10;
    }
    for(i=mini;i<=maxi;i++){
        j=i;
        while(j>=n){
          if(j%nr==n)
          {S++;j=0;}
            j=j/10;
        }
    }g<<S;
}
