#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char sir[256],c,*p; int nr=0;
cout<<"Sirul de caractere "; cin.get(sir,100);
cout<<"Caracterul cautat "; cin>>c;
cout<<"caracterul "<<c<<" apare in pozitiile:"<<endl;
p=strchr(sir,c); //se caut� prima apari�ie
while (p) //c�t timp se g�se�te caracterul
{cout<<p<<" ";nr++;p=strchr(p+1,c);}
/*se caut� urm�toarea apari�ie a caracterului �ncep�nd cu
pozi�ia imediat urm�toare celei �n care a fost g�sit */
cout<< endl<<"apare in "<< nr<< " pozitii";}
