#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char sir1[256], sir2[256];
cout<<"Primul sir de caractere "; cin.get(sir1,100); cin.get();
cout<<"Al doilea sir de caractere "; cin.get(sir2,100);
strncat(sir1,sir2,2); cout<<sir1;}

