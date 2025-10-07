#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int main()
{
    int n;
    char v[100],b[100];
    ifstream f("f1.in");
    f>>n;
    f.ignore();
    f.get(v,100);

//cout<<n<<endl;
    int i,k;
    int m=0,c;
//cout<<v<<endl;
    for(i=strlen(v);; i--)
    {
        if(v[i]==' ')
        {
            c=i;
            break;

        }

    }
    while(m<=c)
    {
        if(strlen(v)-m<=n)
        {
            //cout<<strlen(v)-m<<">>"<<n<<endl;
            for(i=m; i<=strlen(v); i++)
                cout<<v[i];
            break;
        }
        {
            for(i=m; i<m+n; i++)
            {
                if(v[i]==' ')
                    k=i;

            }
            if(v[i+1]==' ')
            {
                for(int j=m; j<=i; j++)
                {
                    cout<<v[j];
                }
                cout<<endl;
                m=i+2;//cout<<"m="<<m<<endl;
            }
            else
            {
                for(int j=m; j<k; j++)
                {
                    cout<<v[j];
                }
                cout<<endl;

                m=k+1;//cout<<"m="<<m<<endl;cout<<strlen(v)<<endl;
            }





        }


    }
}
