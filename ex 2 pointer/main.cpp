#include <iostream>

using namespace std;

int main()
{char a[100],*p;int i=0;
cin>>a;
p=a;
while(*p)
{if(*p=='a'||*p=='e'||*p=='i'||*p=='o'||*p=='u')
   i++;
p++;
}cout<<i;
}
