#include <iostream>
#include <fstream>
using namespace std;

int main()
{ int n;
ifstream f("date.in");int v[10000]={0};
int s=0;
int i=1;f>>n;
while(f>>i)
{v[i]++;
}

for(i=1;;i++)
{
    if(v[i]!=i)
{break;}
else s+=v[i];

}

s+=v[i];

if(s==n)
    cout<<"DA";
    else
cout<<"NU";




}
