#include <iostream>

using namespace std;

int main()
{char s[100];
cin.get(s,100);
int i=1;
s[0]=s[0]-32;
while(s[i]!='\0')
{if(s[i-1]==' ')
s[i]=s[i]-32;
  i++;
}
 cout<<s;
}
