#include <iostream>

using namespace std;

void f(int b)
{
    if(b>=3)
    {
        f(b-2);
        cout<<"*";
    }
    else cout<<b;
}
int main()
{
    int b;cin>>b;f(b);
}
