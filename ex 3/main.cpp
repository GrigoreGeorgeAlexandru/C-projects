#include <iostream>

using namespace std;

int main()
{char a[100];
cin.get(a,100);
int i=1,k=0;
if (a[0]!=','||a[0]!='.'||a[0]!=';'||a[0]!=' ')
k++;
while(a[i]!='\0')
{if( (a[i]!=','&&a[i]!='.'&&a[i]!=';'&&a[i]!=' ')&&(a[i-1]==','||a[i-1]=='.'||a[i-1]==';'||a[i-1]==' ') )
k++;
i++;

}
 cout<<k;
}
