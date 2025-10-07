#include <iostream>

using namespace std;
int sdiv(int n){
int i,S=0;
for(i=1;i<n;i++){
if(n%i==0)
    S=S+i;
}
return S;
}





int main()
{int n1,n2;cin>>n1>>n2;
if(sdiv(n1)==n2&&sdiv(n2)==n1)
    cout<<"prietene";
else
cout<<"nu sunt prietene";

}
