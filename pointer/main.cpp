#include <iostream>

using namespace std;

int main()
{char a[20],b[20],*p,*q;
cin>>a;
p=a;
q=b;

while (*p) *q++=*p++;
*q=*p;
cout<<b;
}
