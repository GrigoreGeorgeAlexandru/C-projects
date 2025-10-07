#include <iostream>

using namespace std;

int main()
{int m=1,i,n,c=0,z=0;cin>>n;
 for(i=2;i<=n;i++)
m=m*i;
while(c==0){
 if(m%10==0)
   z++;
 else
    c=m%10;
 m=m/10;
}
cout<<c<<" "<<z;
}
