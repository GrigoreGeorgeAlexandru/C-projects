#include <iostream>

using namespace std;
void f (int x)
{ if(x>0)
{ cout<<"x";
f(x/3);
cout<<"y";
}
}




int main()
{int x;cin>>x;
f(x);

}
