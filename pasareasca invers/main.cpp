#include <iostream>

using namespace std;

void pasareste(char a[100],int i){
   while(a[i]!='\0'){
    a[i+1]=a[i+2];
    i++;
   }}


int main()
{char a[100];
cin>>a;
int i=0;
while(a[i]!='\0'){
 if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
  {pasareste(a,i);}
    i++;
}cout<<a;}
