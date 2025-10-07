#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a1=0,p1=0;
    int a2=1;
    while(a2!=-1)
    {
        int a2=0,p2=0;
        cin>>a2>>p2;
        if(a1<=a2&&p1<=p2)
        {
            a1=a2;
            p1=p2;
            cout<<"AICI"<<endl;
        }
        else if(a1<a2||p1<p2)
        {
            int s1=0,s2=0;
            s1=abs(a1-a2);
            s2=abs(p1-p2);
            float f=0;
            f=(float)s2/s1;
            cout<<f<<endl;
            if(f==1.5)cout<<"STOP"<<endl;
            else if((f>1.5&&p2>p1)||(f<1.5&&a1<a2))
            {
                a1=a2;
                p1=p2;
                cout<<"AICI"<<endl;
            }

        }
        else
        {
            cout<<"urmatorul"<<endl;
            if(a2!=-1)continue;
            else break;
        }
    }
    return 0;
}
