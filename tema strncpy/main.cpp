#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char sir[20]="0123456789",aux[20],sb[3]="ab",*p; int n=4;
p=&sir[n-1];strcpy(aux,p); strcpy(p+strlen(sb),aux);
strncpy(p,sb,strlen(sb)); cout<<sir;
}
