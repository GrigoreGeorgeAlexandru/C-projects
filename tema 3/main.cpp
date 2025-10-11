#include <iostream>

using namespace std;

int x;
void sb(int &x){
cout<<x;x=1;cout<<x;}
int main()
{
    x=2.5;sb(x);cout<<x;
}
