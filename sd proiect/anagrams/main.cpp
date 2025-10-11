#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{int n;
string v[100001];
   ifstream f("input");
   f>>n;
   for(int i=1;i<=n;i++)
   {
       string cuv;
       f>>cuv;
       sort(cuv.begin(),cuv.end());
       v[i]=cuv;

   }
   sort(v+1,v+n+1);
   int maxi=0;
   int c=1;
   for(int i=1;i<=n;i++)
   { if(v[i]==v[i+1])
        c++;
        else{
            if(c>maxi)
                maxi=c;
            c=1;


        }

   }

   cout<<maxi;

}
