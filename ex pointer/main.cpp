#include <iostream>
using namespace std;

int main()
{char a[100],*p,*q,c;
cin.get(a,100);cin>>c;
p=a;
while(*p!=c)p++;
q=p+1;
while(*q!=c)q++;
cout<<q-p;

}
