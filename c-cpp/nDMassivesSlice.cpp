#include <iostream>
#include <vector>
using namespace std;

int main()
{   
    int i = 0;
    int c = 2;
    vector<vector<vector<int>>> vec3d(c, vector<vector<int>>(c, vector<int>(c, 0)));

    for (int z = 0; z < c; z++)
    {
        for (int y = 0; y < c; y++)
        {
            for (int x = 0; x < c; x++)
            {
                // create
                i++;
                vec3d[z][y][x] = i;
            }
        }
    }
    
    for (int z = 0; z < c; z++)
    {
        for (int y = 0; y < c; y++)
        {
            for (int x = 0; x < c; x++)
            {
                // show
                if (x == 0)
                {
                    int step = 0;
                    for (int i = 0; i < c; i++)
                    {
                        // From every point of 2d slice -> by x axis
                        // on all points of 3d space.
                        cout << vec3d[z][y][x+step];
                        step++;
                    }
                    cout << endl;
                }
            }
        }

    }
    
}