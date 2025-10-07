#include <iostream>
#include <string.h>
using namespace std;

int main()
{char s[200]="abcdefgh";
    strcpy(s+2,s+4); cout<<s<<" "<<strlen(s);
}
