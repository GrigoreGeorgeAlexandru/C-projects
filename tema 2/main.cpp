#include <iostream>

using namespace std;

float x;
void sb(int x)
{
    x=1;
}
int main()
{
    x=2.5;sb(x);cout<<x;
}
