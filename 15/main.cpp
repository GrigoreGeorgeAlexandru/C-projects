#include <iostream>

using namespace std;
long f(long x) {
if (x==4) return x;
else
{ if (x%10==4 || x%10==0) return x+f(x/10);
else return x+f(x*2);
}
}
int main()
{
    cout<<f(34);
}
