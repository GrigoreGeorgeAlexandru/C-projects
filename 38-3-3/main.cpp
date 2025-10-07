#include <iostream>

using namespace std;
int Del(int x,int y){
int i=1,n=0;
while(x>0){
if(x%10<=y){
n=(x%10)*i+n;
i=i*10;
}
x=x/10;
}x=n;
if(x>0)
return x;
else
return-1;
}





int main()
{int x,y;
cin>>x>>y;
cout<<Del(x,y);}

