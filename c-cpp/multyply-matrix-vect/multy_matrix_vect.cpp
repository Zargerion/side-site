#include <iostream>
#include <vector>

using namespace std;

struct vec3 {
    double y,x,z;
    vec3(float _value) : x(_value), y(_value), z(_value) {};
	vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};
};

vec3 VxM(vector<vector<int>> m, vec3 v){
        vec3 result(0);
        result.x = v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2];
        result.y = v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2];
        result.z = v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2];
        return result;
}

vec3 VxV(vec3 v0, vec3 v1){
        vec3 result(0);
        result.x = v0.y * v1.z - v0.y * v1.z;
        result.y = v0.z * v1.x - v0.z * v1.x;
        result.z = v0.x * v1.y - v0.x * v1.y;
        return result;
}

float dot(vec3 const& a, vec3 const& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }


int main(){
    vec3 r(0);
    vec3 rv(0);
    vector<vector<int>> m{{-1, 0, 0}, 
                          {0, -1, 0}, 
                          {0, 0, -1}};
    vec3 vector{2, 0, 0};
    vec3 vector2{4, 4, 4};
    r = VxM(m, vector);
    rv = VxV(vector, vector2);
    float rs = dot(vector, vector2);

    cout << r.x << r.y << r.z << endl;
    cout << rs << endl;
    cout << rv.x << rv.y << rv.z;
}
