#include <iostream>
using namespace std;

int main(void)
{
    int a = 5;
    int *b = &a;
    cout << *b << endl;

    int g= 0;
    
    for (double i = -1; i < 1; i += 0.25)
    {
        for (double j = -1; j < 1; j += 0.25)
        {
            cout<< g << "+++"<< i << " and " << j << endl;
        }
        g++;
    }
}