#include <iostream>

using namespace std;

float normPlusMinusOne(float input, float min, float max)
{
    float average      = (min + max) / 2;
    float range        = (max - min) / 2;
    float normalized_x = (input - average) / range;
    return normalized_x;
}

int main()
{
    float x0 = 0;
    float xmax = 100;
    float out = normPlusMinusOne(2.0, x0, xmax);
    cout << out << "\n";
}