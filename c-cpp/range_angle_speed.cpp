#include <iostream>
#include <cmath>
using namespace std;

float distance(float v, float a)
{
    return v * v * sin(2 * a * M_PI / 180) / 9.81;
}

int main()
{
    float v;
    float a;

    float max_d = 0;
    float max_a = 0;
    float max_v = 0;

    for (v = 1; v < 100; v++)
    {
        for (a = 1; a < 180; a++)
        {
            float d = distance(v, a);
            if (max_d < d)
            {
                max_d = d;
                max_a = a;
                max_v = v;
            }

        }
    }

    cout << "Maximum range equel " << max_d << "m" << " if " << max_v << " m/sec and " << max_a << " degrees." << endl;
}