#include <iostream>

using namespace std;
void f(long int n){
if (n!=0){
if (n%2!=0)
cout<<n%10;
f(n/10);
if (n%2==0)
cout<<n%10;
}
else cout<<endl;
}
int main()
{int n;
cin>>n;
f(n);


}
