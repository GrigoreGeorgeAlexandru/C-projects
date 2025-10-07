#include <iostream>

using namespace std;
void pasareste(char a[100],int i){
    char s1,s2,s3;
   if(a[i+1])
 s1=a[i+1];
else s1='\0';
 a[i+1]='p';
 if(a[i+2])
 s2=a[i+2];
 else s2='\0';
  a[i+2]=a[i];
  i=i+3;
while(s2!='\0'){
 s3=a[i];
 a[i]=s1;
 s1=s2;
 s2=s3;
 i++;
}a[i]=s1;
a[i+1]=s2;}



int main()
{char a[100];
cin>>a;
int i=0;
while(a[i]!='\0'){
 if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
  {pasareste(a,i);
    i=i+3;}
    else i++;
}cout<<a;
}
