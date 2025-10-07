#include <iostream>
#include<fstream>
#include <string.h>
using namespace std;

int main()
{int k;
char bit[1000];
ifstream f("blisin.txt");
f>>k>>bit;
//cout<<bit;
char one[30];int i;
for(i=0;i<k;i++)
    one[i]='1';
    one[k]='\0';
//cout<<one<<" ";
int q=0;
while(q==0)
{if(strstr(bit,one))
q=1;
else {
if(one[k-1]=='1')
one[k-1]='0';
else
{int k2=k,w=0;
while (w==0)
{if(one[k2-1]=='0')
{one[k2-1]='1';k2--;
}else{one[k2-1]='0';w=1;}
}
}
}
}
//cout<<one;
int nr=strlen(one);



}

