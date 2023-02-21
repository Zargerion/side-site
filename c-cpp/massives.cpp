#include <iostream>
#include <vector>

using namespace std;

const int y = 10;
const int x = 20;

void VectorShow(vector<vector<int>>&v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j];
        }    
        cout << endl;
    }
}

void MassiveShow(int massive[][x])
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << massive[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int massive[y][x];

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            massive[i][j] = 1;
        }
        
    }

    vector<vector<int>> vec(y, vector<int>(x));

    //for (int i = 0; i < vec.size(); i++)
   // {
    //    for (int j = 0; j < vec[i].size(); j++)
    //    {
    //        vec[i][j] = 1;
   //     }    
   // }

    fill(vec.begin(), vec.end(), vector<int>(x, 4));

    cout << endl << "Vector" << endl << endl;
    VectorShow(vec);

    cout << endl << "---------------------------" << endl;
    
    cout << endl << "Massive" << endl << endl;
    MassiveShow(&massive[0]);

    cout << endl;



    return 0;
}

