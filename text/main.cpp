#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{ char text[20000][20];int i=0;
ifstream f("textin.txt");
ofstream g("textout.txt");
while(!f.eof())
{f>>text[i];
i++;
}int j;
/*
for(j=0;j<i;j++)
cout<<text[j]<<j;*/
int nrcuv=i;
g<<nrcuv<<" ";g<<endl;


int nrc=i,cost[20000],vect[256]={0};
cost[0]=1;
char litera;
litera=text[0][strlen(text[0])-1];
vect[litera]=1;
for(i=1;i<nrc;i++)
{litera=text[i][strlen(text[i])-1];
cost[i]=vect[text[i][0]]+1;
if(cost[i]>vect[litera])
    vect[litera]=cost[i];
}
/*for(i=0;i<nrc;i++)
cout<<cost[i]<<" ";cout<<endl;*/
int mini=0;
for(i=0;i<nrc;i++)
if(mini<cost[i])
mini=cost[i];g<<nrcuv-mini<<" ";g<<endl;
int constant=mini;

for(i=0;i<nrc;i++)
    if(cost[i]==mini)
    break;int pozitii[20000];j=1;
int pozitie=i;//cout<<pozitie<<" ";
pozitii[j]=pozitie;j++;

 while(mini>0)
{char primalitera;
primalitera=text[pozitie][0];//cout<<primalitera;
mini--;
for(i=0;i<nrc;i++)
    if(cost[i]==mini&&text[i][strlen(text[i])-1]==primalitera)
   {pozitie=i;//cout<<pozitie<<" ";
       break;
   }
pozitii[j]=pozitie;j++;
}
for(i=constant;i>0;i--)
  {g<<text[pozitii[i]]<<" ";
  g<<endl;}
}
