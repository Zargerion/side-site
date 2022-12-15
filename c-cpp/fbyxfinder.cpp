#include <iostream>
#include <cmath>
using namespace std;

float f(float x)
{
    return x - 4; // Any of the eqution equel 0. Linear for exemple.
}

float n(float x1, float x2)
{
    float x = (x2 + x1) / 2;
    while (abs(f(x)) > 0.001)
    {
        if (f(x) > 0)
        {
            x2 = x;
        }
        else
        {
            x1 = x;
        }
        x = (x2 + x1) / 2; // Every times while mudule f(x) > 0.001 line sigment will be narrows down by x1 and x2.
    }
    return x;
}

int main()
{
    cout << n(0.00, 100.00) << endl; // Function n makes a line sigment.
}