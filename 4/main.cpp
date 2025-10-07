#include <iostream>

using namespace std;
void f (int n, int x)
{ if(x>n)
cout<<"*";
else
{ f(n,x+4);
cout<<x%10;
}
}
int main()
{int n,x;
cin>>x>>n;
f(n,x);
}
