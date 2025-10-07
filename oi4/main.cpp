#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;

int main()
{
    char M[5][512],maxi[512],f[500],y,d[500]="\0";
    int n,i,j,nrl=500,k,nr;
    ifstream g("subsecventein.txt");
    g>>n;
    for(i=0; i<n; i++)
    {
        g>>M[i];
        if(strlen(M[i])<nrl)
        {
            nrl=strlen(M[i]);
            nr=i;
        }
    }
    for(i=0; i<nrl; i++)
        for(j=i; j<nrl; j++)
        {
            for(k=i; k<=j; k++)
                f[k-i]=M[nr][k];
            f[j-i+1]='\0';
            cout<<f<<endl;

            y=0;
            for(k=0; k<n; k++)
                if(!strstr(M[k],f))
                {
                    y=1;
                    break;
                }
            if(y==0&&strlen(f)>strlen(d)) strcpy(d,f);
            cout<<strlen(d);

        }
    cout<<d<<endl;
}
