#include <iostream>
#include<string.h>
using namespace std;

int main()
{char text[255],c,*vocala=" aeiou";
cin.get(text,255);
int i,n=strlen(text);
i=n-1;
while(strchr(vocala,text[i]))
    i--;

  cout<<text[i];
}
