#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int number;
int base;
int sum = 0;
int i = 0;

std::cout << "Input a number: ";
std::cin >> number;
std::cout << "Input a base: ";
std::cin >> base;
std::cout << endl;

while (number != 0)
{
    int lastDigit = number % 10;
    sum += lastDigit * pow(base, i);
    i++;
}

std::cout << "This number in base 10 is " << sum;

return 0;
}
