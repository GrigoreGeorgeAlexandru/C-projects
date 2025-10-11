#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char sir[256],c,*p; int nr=0;
cout<<"Sirul de caractere "; cin.get(sir,100);
cout<<"Caracterul cautat "; cin>>c;
cout<<"caracterul "<<c<<" apare in pozitiile:"<<endl;
p=strchr(sir,c); //se cautã prima apariþie
while (p) //cât timp se gãseºte caracterul
{cout<<p<<" ";nr++;p=strchr(p+1,c);}
/*se cautã urmãtoarea apariþie a caracterului începând cu
poziþia imediat urmãtoare celei în care a fost gãsit */
cout<< endl<<"apare in "<< nr<< " pozitii";}
