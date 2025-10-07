#include <iostream>
#include <fstream>
using namespace std;

int main()
{ ifstream f("fractii2in.txt");
ofstream g("fractii2out.txt");
int p,n;
f>>p>>n;
if(p==1){
 g<<n-1<<" ";
     while(n>1)
 {g<<n-1<<" ";
 n--;}
}
if(p==2){


}
}
