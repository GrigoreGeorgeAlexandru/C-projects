#include <iostream>

using namespace std;

int a,b,c;
void sb(int &b){cout<<a<<" "<<b<<" "<<c<<" ";}
int main(){
    cout<<a<<" "<<b<<" "<<c<<" "; a=10;b=20;c=30;sb(a);
    cout<<a<<" "<<b<<" "<<c<<" ";
}
