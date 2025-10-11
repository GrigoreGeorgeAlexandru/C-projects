#include <iostream>
using namespace std;
const unsigned NMAX=100;
typedef int nod;
nod stiva[NMAX+1],val;
unsigned vf,baza;
int este_vida(int vf)
{
    return vf==0;
}
int este_plina(int vf)
{
    return vf==NMAX;
}
void init(int &vf)
{
    vf=0;
}
void adauga(int &vf,nod val)
{
    if(!este_plina(vf))
    {
        vf++;
        stiva[vf]=val;

    }

}
void extrage(int &vf)
{
    if(!este_vida(vf))
        vf--;
}
int prelucrare(int &vf)
{int S=0;
    while(!este_vida(vf))
    {S+=stiva[vf];
        extrage(vf);

    }return S;
}



int main()
{nod cif;int vf;init(vf);
cout<<"introduceti numerele: "<<endl;
cout<<"numar= ";cin>>cif;
while(cif!=0&&!este_plina(vf))
{adauga(vf,cif);
cout<<"numar= ";cin>>cif;}
cout<<"Totalul este: ";cout<<prelucrare(vf);

}
