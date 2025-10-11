#include <iostream>

using namespace std;

void fct(int a,int &b)
{
a++;
b--;}

int main()
{
    int a=3,b=7;
    fct(a,b);
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    return 4;}

