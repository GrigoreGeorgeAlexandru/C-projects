#include <iostream>
#include <string.h>
using namespace std;

int main()
{int i=0;
char s[]="abbacdde";
while (i<strlen(s)-1)
if (s[i]==s[i+1])
{ strcpy(s+i,s+i+1);
if (i>0) i=i-1;
}
else i=i+1;
cout<<s;
}
