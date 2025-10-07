#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char a[255];
    cin.get (a,255);
    int i,j,nr=0;
    for(i=0; i<strlen(a); i++)
    {
        if(a[i-1]==' '&&a[i]!=' ')
        {
            for(j=i;; j++)
                if(a[j]!=' ')
                {
                    cout<<a[j]<<endl;
                    if(a[j]>='A'&&a[j]<='Z')
                        nr++;
                }
                else break;
            break;
        }
    }
    cout<<nr;


}
