#include <iostream>
#include <fstream>
using namespace std;

int main()
{int i=1,m=0,maxi,a,S=0,v[7];
    ifstream f("bakugan.in");
    ofstream g("bakugan.out");
    while(f>>v[1]>>v[2]>>v[3]>>v[4]>>v[5]>>v[6])
    {S=0;
        for(i=1;i<=6;i++)
     {if(v[i]>m)m=v[i];}
     for(i=1;i<=6;i++)
{if(v[i]!=m){S+=v[i];}//cout<<v[i]<<" "<<S<<endl;}
else {S+=-5*v[i];m=0;a=i;}//cout<<v[i]<<" "<<S<<endl;}
}if(a==1)g<<"pyrus ";if(a==2)g<<"aquos ";if(a==3)g<<"subterra ";if(a==4)g<<"haos ";if(a==5)g<<"darkus ";if(a==6)g<<"ventus "; g<<S<<endl;
}
}
