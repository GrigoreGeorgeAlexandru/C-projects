#include <iostream>

using namespace std;

int main()
{char c,s[100];
cin>>s>>c;
int i=0,k=0;
while(s[i]!='\0')
{if(s[i]==c)
k++;
i++;
}
cout<<k;
}
