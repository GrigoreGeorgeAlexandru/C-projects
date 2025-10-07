#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
    char s[102];int i;
    ifstream f("text.in");
f>>s;
    char c[102];
f>>c;cout<<c;
    char sir[102];
    sir[0]=s[0];sir[1]='/0';
    int p=1;

cout<<endl;
    for(i=1; i<strlen(s); i++)
    {
        if(c[i]%2!=0)
        {
            sir[p]=s[i];
            p++;
sir[p]='\0';
        }
        else
        {
            int j;
            for(j=p; j>=0; j--)
                sir[j+1]=sir[j];

            sir[0]=s[i];
p++;sir[p]='\0';
        }

    }


    cout<<sir;

}
