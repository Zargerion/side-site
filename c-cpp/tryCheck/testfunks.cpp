#include <iostream>
#include "fortestfunk.h"

using namespace std;


int main()
{
    vec2 v2(10, 20);
    vec3 v3(10, 20, 1000);
    vec3 n(77);
    vec3 b = reflect(v3 ,n);

    vec3 a = norm(v3);

    cout << a.x << " " << a.y << " " << a.z << endl;
    
}