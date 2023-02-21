#include <iostream>
#include <vector>
#include <complex>
#include <ctime>
#include <windows.h>
#include <cassert>
#include <fstream>

#define M_PI 3.14159265358979323846

using namespace std;

struct vec2
{
	float x, y;

	vec2(float value) : x(value), y(value) {}
	vec2(float _x, float _y) : x(_x), y(_y) {}

	vec2 operator+(vec2 const& other) { return vec2(x + other.x, y + other.y); }
	vec2 operator-(vec2 const& other) { return vec2(x - other.x, y - other.y); }
	vec2 operator*(vec2 const& other) { return vec2(x * other.x, y * other.y); }
	vec2 operator/(vec2 const& other) { return vec2(x / other.x, y / other.y); }
};

struct vec3
{
	int x, y, z;

	vec3(float _value) : x(_value), y(_value), z(_value) {};
	vec3(float _x, vec2 const& v) : x(_x), y(v.x), z(v.y) {};
	vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};

	vec3 operator+(vec3 const& other) { return vec3(x + other.x, y + other.y, z + other.z); }
	vec3 operator-(vec3 const& other) { return vec3(x - other.x, y - other.y, z - other.z); }
	vec3 operator*(vec3 const& other) { return vec3(x * other.x, y * other.y, z * other.z); }
	vec3 operator/(vec3 const& other) { return vec3(x / other.x, y / other.y, z / other.z); }
	vec3 operator-() { return vec3(-x, -y, -z); }

    friend ostream& operator<<(ostream &os, const vec3& d) {
    return os << (char) (d.x % 256) << (char) (d.y % 256) << (char) (d.z % 256);
    }
};   

void render() {
    const int width    = 400;
    const int height   = 300;
    std::vector<vector<vec3>> framebuffer(height, vector<vec3>(width, vec3(255, 0, 0)));

    for (size_t j = 0; j<height; j++) {
        for (size_t i = 0; i<width; i++) {
            
            if (((i - width / 2) * (i - width / 2) + (j - height / 2) * (j - height / 2) <= height*width/20))
            {
                framebuffer[j][i] = vec3(0, 55, 0);
            }
            
        }
    }


    vec2 cam(0, 0);
    float angle = 0.25;
    for (size_t i = 0; i < width*height/2; i++)
    {
        for (size_t j = 0; j < width*height/4; j++)
        {
            int matrix[2][2] = {{0,2}, 
                                {2,0}};
            vec2 XY = cam * matrix;
            framebuffer[XY.x][XY.y];
        }  
    }
    

    
    std::ofstream ofs; // save the framebuffer to file
    ofs.open("./out.ppm", ios_base::out | ios_base::binary);
    ofs << "P6" << "\n";
    ofs << width << " " << height << "\n";
    ofs << 255 << "\n";
    for (size_t j = 0; j<height; j++) {
        for (size_t i = 0; i<width; i++) {
        ofs << framebuffer[j][i];
        }
    }
    ofs.close();
}

int main() {
    render();
}
