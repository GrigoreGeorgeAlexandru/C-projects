#include <iostream>

using namespace std;
int f(int n){
if (n==0) return 0;
else
if (n%2==0)
return n%10+f(n/10);
else return f(n/10);
}
int main()
{
    cout<<f(23169);
}
