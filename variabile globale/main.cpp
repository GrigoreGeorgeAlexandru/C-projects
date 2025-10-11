#include <iostream>

using namespace std;

int a;
int fct()
{int x=5;
a=a+2;
return x;

}
int main()
{a=3;
cout<<"a="<<a<<endl;
cout<<"x="<<fct()<<endl;
cout<<"a="<<a<<endl;
}
