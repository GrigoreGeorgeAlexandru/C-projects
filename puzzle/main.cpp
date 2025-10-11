#include <iostream>

using namespace std;

int main()
{int i;
for(i=100;i<1000;i++){
  if(i+i%10*10+i%100/10+i/100*100==i%10*100+i%100/10*10+i/100){
    cout<<i<<" ";
  }
}

}
