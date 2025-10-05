#include <iostream>

using namespace std;
long f(long n)
{ if (n==0) return 1;
else
if (n%10==0)
return f(n/10);
else
return (n%10) * f(n/10);}
int main()
{
    cout<<f(4063);
}
