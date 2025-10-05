#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[13]="abcdefghoid";
cout<<strlen(s);

for (int i=0;i< strlen(s);i++)
if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
s[i]= s[i]-'a'+'A';
cout<<" "<<s;
}
