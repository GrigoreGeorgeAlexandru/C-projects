#include <iostream>
#include <fstream>
using namespace std;



int main()
{long long a,b,c,nrp=0;
   ifstream f("armonicain.txt");
   ofstream g("armonicaout.txt");
   f>>b;
 for(a=1;a<=b;a++)
    if(2*a-b>0&&(b*a)%(2*a-b)==0)
  {c=(b*a)/(2*a-b);
 nrp++;
 if(a!=c)
    nrp++;
 }
 g<<nrp;
 g<<endl;
 for(a=1;a<=b;a++)
    if(2*a-b>0&&(b*a)%(2*a-b)==0)
  {c=(b*a)/(2*a-b);

    g<<a<<" "<<c;g<<endl;
    if(c>b)
    g<<c<<" "<<a;g<<endl;

    }

}
