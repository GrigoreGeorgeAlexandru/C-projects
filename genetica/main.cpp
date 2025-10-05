#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <math.h>
#include <bitset>
#include <string.h>
#include <iomanip>
using namespace std;
int dimensiune,dominin,domaxim,a,b,c,precizie,etape;
float probrec,probmut;float sumap;
float v[100];
string str[100];
float func[100];
float probsel[100];
float intervalprob[100];
int indexnewgen[100];
int indexparticipa[100];
int indexnuparticipa[100];
int newindex[100];
string newstr[100];
float newv[100];
float newfunc[100];
float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}
int Binary2Hex( string Binary )
{
    bitset<32> set(Binary);
    int hex = set.to_ulong();

    return hex;
}
float GetFloat32( string Binary )
{
    int HexNumber = Binary2Hex( Binary );

    bool negative  = !!(HexNumber & 0x80000000);
    int  exponent  =   (HexNumber & 0x7f800000) >> 23;
    int sign = negative ? -1 : 1;


    exponent -= 127;


    int power = -1;
    float total = 0.0;
    for ( int i = 0; i < 23; i++ )
    {
        int c = Binary[ i + 9 ] - '0';
        total += (float) c * (float) pow( 2.0, power );
        power--;
    }
    total += 1.0;

    float value = sign * (float) pow( 2.0, exponent ) * total;

    return value;
}


string GetBinary32( float value )
{
    union
    {
         float input;
         int   output;
    }    data;

    data.input = value;

    bitset<sizeof(float) * CHAR_BIT>   bits(data.output);

    string mystring = bits.to_string<char,
                                          char_traits<char>,
                                          allocator<char> >();

    return mystring;
}
float functcalc(float x){
    float sol= x*x*x+x*x*3-4*x+7;
    return sol;


}


int bsearch(float f){

int n = dimensiune;
    int low = 1;
    int high = n;
    int mid;
    while(low <= high) {
    int oldmid=mid;
      mid=low+(high-low)/2;
      if(oldmid==mid)
        break;
      if(intervalprob[mid]<=f)
        low=mid;
      else if(intervalprob[mid]>f)
        high=mid;

    }

    return mid+1;


}


int main()
{ifstream f("text.in");
ofstream g("text.out");
   f>>dimensiune>>dominin>>domaxim>>a>>b>>c>>precizie>>probrec>>probmut>>etape;

 g << fixed << showpoint;
    g << setprecision(precizie);
   for(int i=1;i<=dimensiune;i++)
   {v[i]=RandomFloat(dominin,domaxim);
    str[i] = GetBinary32( v[i] );
    func[i]=functcalc(v[i]);
    if(i<10)
       g<<" ";
    g<<i<<": "<<str[i]<<" x= "<<v[i]<<" f="<<func[i]<<endl;
   }
   int nr=1;
while(nr<=etape){


float maxi1=0;
int indexmaxi;
  for(int i=1;i<=dimensiune;i++)
   {

   sumap+=func[i];
   if(maxi1<func[i])
   {maxi1=func[i];
   indexmaxi=i;

   }
   }

if(nr==1)g<<endl<<"Probabilitati selectie"<<endl;
     for(int i=1;i<=dimensiune;i++)
     {
         probsel[i]=func[i]/sumap;
        if(nr==1)g<<"cromozom  ";
          if(i<10)
        if(nr==1)g<<" ";
         if(nr==1)g<<i<<" probabilitate "<<probsel[i]<<endl;
     }

if(nr==1)g<<endl<<"Intervale proabilitati selectie"<<endl;
float suma1=0;
if(nr==1)g<<suma1<<" ";
for(int i=1;i<=dimensiune;i++)
{suma1+=probsel[i];
intervalprob[i]=suma1;
if(nr==1)g<<suma1<<" ";

}
if(nr==1)g<<endl;

for(int i=1;i<=dimensiune;i++)
{
    float randomnum=RandomFloat(0,1);
if(nr==1)g<<"u= "<<randomnum<<" selectam cromosomul ";
indexnewgen[i]=bsearch(randomnum);
if(nr==1)g<<indexnewgen[i]<<endl;


}
if(nr==1)g<<"Indice de fitness maxim "<<maxi1<<" selectam cromosomul "<<indexmaxi<<endl;
indexnewgen[20]=indexmaxi;

if(nr==1)g<<"Dupa selectie: "<<endl;
 for(int i=1;i<=dimensiune;i++)
 {if(i<10)
        if(nr==1)g<<" ";
         if(nr==1)g<<i<<": "<<str[indexnewgen[i]]<<" x= "<<v[indexnewgen[i]]<<" f="<<func[indexnewgen[i]]<<endl;
 }
 int parlen=1;
 int nuparlen=1;
if(nr==1)g<<"Probabilitatea de incrucisare "<<probrec<<endl;

for(int i=1;i<=dimensiune;i++)
 {if(i<10)
        if(nr==1)g<<" ";
        float currentrandom=RandomFloat(0,1);
         if(nr==1)g<<i<<": "<<str[indexnewgen[i]]<<" u= "<<currentrandom;

         if(currentrandom<probrec)
        {if(nr==1)g<<"<"<<probrec<<" participa"<<endl;
        indexparticipa[parlen]=indexnewgen[i];  newindex[parlen]=i;
parlen++;
        }
        else {if(nr==1)g<<endl;
         indexnuparticipa[nuparlen]=indexnewgen[i];
        nuparlen++;
        }
 }

if((parlen-1)%2==1)
 {indexnuparticipa[nuparlen]=indexparticipa[parlen-1];

    parlen--;

    }
    parlen--;

    for(int i=1;i<=parlen;i=i+2)
{if(nr==1)g<<"Recombinare dintre cromzomul "<<newindex[i]<<" cu cromozomul "<<newindex[i+1]<<":"<<endl;
if(nr==1)g<<str[indexparticipa[i]]<<" / "<<str[indexparticipa[i+1]]<<" punct ";
int random=(int)RandomFloat(0,str[1].size());
if(nr==1)g<<random<<endl;
for(int j=random-1;j<str[1].size();j++)
{char aux;
    aux=str[indexparticipa[i]][j];
    str[indexparticipa[i]][j]=str[indexparticipa[i+1]][j];
    str[indexparticipa[i+1]][j]=aux;
}
if(nr==1)g<<"Rezultat  ";
if(nr==1)g<<str[indexparticipa[i]]<<" / "<<str[indexparticipa[i+1]]<<endl;
indexnuparticipa[nuparlen]=indexparticipa[i];nuparlen++;
indexnuparticipa[nuparlen]=indexparticipa[i+1];nuparlen++;
}

if(nr==1)g<<"Dupa recombinare:"<<endl;
for(int i=1;i<=dimensiune;i++)
{newstr[i]=str[indexnuparticipa[i]];
newv[i]=GetFloat32(newstr[i]);
newfunc[i]=functcalc(newv[i]);
if(i<10)
        if(nr==1)g<<" ";

        if(nr==1)g<<i<<": "<<newstr[i]<<" x= "<<newv[i]<<" f="<<newfunc[i]<<endl;
}
if(nr==1)g<<"Probabilitate de mutatie pentru fiecare gena "<<probmut<<endl;
if(nr==1)g<<"Au fost modificati cromozomii:"<<endl;
for(int i=1;i<=dimensiune;i++)
{float currentrandom=RandomFloat(0,1);
         if(currentrandom<probmut)
{if(nr==1)g<<i<<endl;
int random=(int)RandomFloat(0,str[1].size()-1);
if(newstr[i][random]=='1')
newstr[i][random]='0';
else newstr[i][random]='1';
newv[i]=GetFloat32(newstr[i]);
newfunc[i]=functcalc(newv[i]);
}
}
if(nr==1)g<<"Dupa mutatie:"<<endl;
for(int i=1;i<=dimensiune;i++)
{

  if(i<10)
        if(nr==1)g<<" ";

        if(nr==1)g<<i<<": "<<newstr[i]<<" x= "<<newv[i]<<" f="<<newfunc[i]<<endl;}
 for(int i=1;i<=dimensiune;i++)
 {
     str[i]=newstr[i];
     v[i]=newv[i];
     func[i]=newfunc[i];
 }

 if(nr==1)g<<endl<<"Evolutia maximului       Valoara medie a performantei"<<endl;
float sum=0;
float maxi=0;
for(int i=1;i<=dimensiune;i++)
{sum+=func[i];
if(func[i]>maxi)
    maxi=func[i];

}
 g<<maxi<<"                 "<<sum/dimensiune<<endl;
nr++;}
return 0;
}
