#include <iostream>

using namespace std;
int f(int n){
int c;
if(n!=0){
 if(n%2==1)
 c=1+f(n/2);
 else c=f(n/2);
 cout<<n%2;
 return c;
}
else return 0;
}




int main()
{int n;cin>>n;cout<<f(n);

}
