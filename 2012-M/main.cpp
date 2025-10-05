#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main()
{
   ifstream f("date.in");

   int v[100];
   int n;

   f>>n;

   int i;

   for(i=1;i<=n;i++)
    f>>v[i];

   float s=0;

   s=s+v[1]+v[n];
   for(i=2;i<=n;i++)
   {s+=sqrt((v[i]+v[i-1])*(v[i]+v[i-1])-abs(v[i]-v[i-1])*abs(v[i]-v[i-1]));
   }
   cout<<setprecision(4)<<s;

}
