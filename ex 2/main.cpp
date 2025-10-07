#include <iostream>

using namespace std;

int main()
{char b[100];
cin.get(b,100);
int i=0,k=0;
while(b[i]!='\0')
{if(b[i]=='a'||b[i]=='e'||b[i]=='i'||b[i]=='o'||b[i]=='u')
    k++;
i++;
}cout<<k;
}
