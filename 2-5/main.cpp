#include <iostream>

using namespace std;

int main()
{ char a[21];
    cin>>a;
    int i;
    for(i=0;i<20;i++)
    {   if(a[i]>='a'&&a[i]<='z')
        a[i]=a[i]-32;

}
    cout<<a;
}
