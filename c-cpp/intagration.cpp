#include <iostream>
#include <cmath>
using namespace std;

float dist(float v, float a)
{
    float x = 0;
    float y = 0;

    float vx = v * cos(a * M_PI / 180); // vector by x
    float vy = v * sin(a * M_PI / 180); // vector by y _ all is vector trajectory
    float dt = 0.0001;

    while (y >= 0)
    {
        x += vx * dt;
        y += vy * dt;
        
        vy -= 9.81 * dt;
    }

    return x;
}

int main(void)
{
    cout << dist(99.00, 45.00) << endl;
}