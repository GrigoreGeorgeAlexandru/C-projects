#include <iostream>

using namespace std;

int a,b;
int sb(int a)
{
    int i=0;while(a!=0){a/=10;i++;}
    cout<<b;return i;

}
int main(){a=12345;b=sb(a);cout<<b;}
