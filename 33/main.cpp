#include <iostream>

using namespace std;

void impar(int x[],int n){
int i,f=0;
for(i=1;i<=n;i++){
 if(x[i]%2!=0)
    f=1;
}
if(f==1)
    cout<<"DA";
else
    cout<<"NU";

}





int main()
{

}
