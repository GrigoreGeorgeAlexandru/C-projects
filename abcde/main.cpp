#include <iostream>

using namespace std;

int main()
{int i;
for(i=10000;i<100000;i++)
if(i/10000==i*4%10&&i/1000%10==i*4/10%10&&i/100%10==i*4/100%10&&i/10%10==i*4/1000%10&&i%10==i*4/10000)
cout<<i<<" ";
    return 0;
}
