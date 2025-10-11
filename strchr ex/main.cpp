#include <iostream>
#include<string.h>
using namespace std;

int main()
{char sir[256],c,*p1,*p2;
cin.get(sir,100);
cin>>c;
p1=strchr(sir,c);
p2=strchr(p1+1,c);
cout<<p2-p1-1;
}
