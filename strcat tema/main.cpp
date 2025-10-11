#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  cout<<strcmp("ab","a")<<" ";cout<<strcmp("ab","abc")<<" ";
cout<<strcmp("ab","Ab")<<" "; cout<<strncmp("abc","abcd",3)<<" ";
}
