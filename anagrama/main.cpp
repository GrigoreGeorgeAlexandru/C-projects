#include <iostream>
#include<cstring>
using namespace std;

int main()
{char a[100],b[100];
cin>>a>>b;
    int i=0,j=0,imax,jmax,f=0;
    imax=strlen(a);
    jmax=strlen(b);
    while(i<=imax)
    {while(j<=jmax)
    {if(a[i]==b[j])
    {b[j]=' ';f++;i++;j=-1;

    }
        j++;
    }

    }
    if(f==imax+1)
cout<<"DA";else
cout<<"NU";



}

