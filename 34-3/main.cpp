#include <iostream>
#include<fstream>
using namespace std;

int cifre_impare(int n){
while(n>0){
if((n%10)%2==0)
    return 0;
else
    n=n/10;
}
return 1;

}
int main()
{ ifstream f("numere.txt");
int n,x,i;f>>n;
for(i=1;i<=n;i++){
    f>>x;
    if(cifre_impare(x)&&x>100)
        cout<<x<<" ";
}

}
