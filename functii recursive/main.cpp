#include <iostream>

using namespace std;
int suma(int n){
if(n==0){
    return 0;}
    return n+suma(n-1);
}



int main()
{int n;cin>>n;
   cout<<suma(n);
}
