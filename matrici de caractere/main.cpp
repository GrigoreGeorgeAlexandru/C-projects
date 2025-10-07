#include <iostream>
#include <fstream>
#include<string.h>
#include<conio.h>
using namespace std;

int main()

{char elevi[30][15],aux[15];
unsigned i,n,ok,m;
ifstream cl("clasa.in.txt");
cl>>n;
m=n;
for(i=0;i< n;i++)
cl>>elevi[i];
do //ordonare prin metoda bulelor
{ok=1;
for(i=0;i<n-1;i++)
if(strcmp(elevi[i],elevi[i+1])>0)
{ok=0;
strcpy(aux,elevi[i]);
strcpy(elevi[i],elevi[i+1]);
strcpy(elevi[i+1],aux);
}
n--;
}while(!ok);
cout<<"Lista numelor ordonate alfabetic: "<<endl;
    for(i=0;i< m;i++)
cout<<elevi[i]<<endl;
getch();
}



