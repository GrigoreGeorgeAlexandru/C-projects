#include <iostream>
#include<string.h>
using namespace std;

int main()
{
   int i=0; char s[11]="abaemeiut";
cout<<strlen(s);
while (i<strlen(s))
if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
{ strcpy(s+i,s+i+1); i=i+1; }
else
i=i+2;
cout<<" "<<s;
}
