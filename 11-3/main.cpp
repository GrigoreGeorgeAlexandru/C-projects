#include <iostream>
#include <string.h>
using namespace std;

int main()
{char s[12]="abcdefghijkl";cout<<s[10];
strcpy(s,"abracadabra");
int i=0;
cout<<strlen(s);
while (i<strlen(s))
if (s[i]=='a')
strcpy(s+i,s+i+1);
else i++;

cout<<" "<<s;
}
