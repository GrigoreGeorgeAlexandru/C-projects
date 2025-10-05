#include <iostream>

using namespace std;


float nreal(float x,float y){
while(y>1){
  y=y/10;
}
x=x+y;
return x;
}



int main()
{float x,y,z;cin>>x>>y;
z=nreal(x,y);cout<<z;
    return 0;
}
