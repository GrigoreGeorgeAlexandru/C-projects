#include <iostream>
#include <string.h>
using namespace std;

int main()
{
   char a[25]= "acesta este un exemplu",b[15]="un exemplu";
int i;
for(i=0;i<=21;i++)
    if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
    strcpy(a+i,a+i+1);
cout<<a;
}
