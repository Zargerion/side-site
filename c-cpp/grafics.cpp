#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    class Array
    {
    public:
        int x;
        int y;
    };

    Array massive[10];

    for (int i = 1; i < sizeof(massive) / sizeof(massive[0]); i++) // Becouse sizeof(massive) is quantity of bites of all massive
                                                                   // so sizeof(massive) / sizeof(massive[0]) is a count
                                                                   // of massive units.
    {

        massive[i].x = i * i;
        massive[i].y = i * 2;
    }

    for (int i = 1; i < sizeof(massive) / sizeof(massive[0]); i++)
    {
        cout << massive[i].x << " and " << massive[i].y << endl;
    }

    // ----------------------------------------------------------------------------------------------------

    char m[30][30];

    const int h = sizeof(m) / sizeof(m[0]);
    const int w = sizeof(m) / sizeof(m[0]);

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++) // Makes horizontal lines so it's x.
        {
            m[y][x] = '#';
        }
    }

    char notconstchar = '@'; // So "" const char* - '' not a const char* (is a char).

    for (int x = 0; x < w; x++)
    {
        int y = h - x * x * h / (w * w); // Equation "y = x * x". Part h / (w * w) is
                                         // a k like 0.00123 that limits y in h and w. Part "h - equation" is make to
                                         // values of y comes by reverse way.
        if ((y >= 0) && (y < h))
        {
            m[y][x] = notconstchar;
        }
    }

    for (int x = 0; x < w; x++)
    {
        int y = (sin(1.0 * x * 2 * M_PI / w) + 1) / 2 * h;
        if ((y >= 0) && (y < h))
        {
            m[y][x] = '+';
        }
    }

    for (int x = 0; x < w; x++)
    {
        int y = sqrt(30 * 30 - x * x);
        if ((y >= 0) && (y < h))
        {
            m[y][x] = '.';
        }
    }

    const int reducedw = w / 5;

    for (int y = 0; y < w; y++)
    {
        for (int x = 0; x < h; x++)
        { 
            // If x - x0 (any of x value) so it goes right, if y - y0 then it goes up. But here down.
            // Becouse grafic is making from top to bottom... Grafic swifts by w (width) / 2 by axis x, y. 
            // That deploys it on center. Map is (if < 30) or (if > 40) and (if < 50).
            // So if adjust x - x0, y - y0, z - z0 dinamic that can make animation. Cercle.
            if (((x - w / 2) * (x - w / 2) + (y - w / 2) * (y - w / 2)) <= reducedw / 2 || 
                ((((x - w / 2) * (x - w / 2) + (y - w / 2) * (y - w / 2) >= reducedw * 2)) &&
                 (((x - w / 2) * (x - w / 2) + (y - w / 2) * (y - w / 2) <= reducedw * 4))))   
                                                                                      
            {
                m[y][x] = '=';
            }
        }
    }

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++) // Makes horizontal lines so it's x.
        {
            cout << m[y][x];
        }
        cout << endl;
    }
}