#include <iostream>
#include <vector>
#include <complex>
#include <ctime>
#include <windows.h>
#include <cassert>

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

    friend ostream& operator<<(ostream &os, const vec2& d) {
    return os  << '(' << d.x << ", " << d.y << ')' << endl;
}

};

struct vec3
{
	float x, y, z;

	vec3(float _value) : x(_value), y(_value), z(_value) {};
	vec3(float _x, vec2 const& v) : x(_x), y(v.x), z(v.y) {};
	vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};

	vec3 operator+(vec3 const& other) { return vec3(x + other.x, y + other.y, z + other.z); }
	vec3 operator-(vec3 const& other) { return vec3(x - other.x, y - other.y, z - other.z); }
	vec3 operator*(vec3 const& other) { return vec3(x * other.x, y * other.y, z * other.z); }
	vec3 operator/(vec3 const& other) { return vec3(x / other.x, y / other.y, z / other.z); }
	vec3 operator-() { return vec3(-x, -y, -z); }

    friend ostream& operator<<(ostream &os, const vec3& d) {
    return os  << '(' << d.x << ", " << d.y << ", " << d.z << ')' << endl;
}
};

class size {
protected:
const int m_y_size = 30;
const int m_x_size = 30;
const int m_z_size = 30;
};

class geometry : protected size {
    protected:
    bool line(float x, float y, float z){
        if (x*x + y*y + z*z <= 0.05){ return true; }
        else { return false; }
    }
    float length(vec3 const& v){ 
        return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); 
    }
    vec3 norm(vec3 v) { return v / length(v); }
};

class canvas : private geometry {
    private:
    vector<unsigned char> m_vector1d = vector<unsigned char>(m_x_size*m_y_size, '#');
    vector<unsigned char> m_vector1dSpace = vector<unsigned char>(m_x_size*m_y_size*m_z_size, '#');
    public:
    vector<unsigned char> write(){
        for (int z = 0; z < m_z_size; z++){
            for (int y = 0; y < m_y_size; y++){
                for (int x = 0; x < m_x_size; x++){
                    vec3 rd = vec3(x, y, z) / vec3(m_x_size, m_y_size, m_z_size) * 2.0f - 1.0f; //
                    rd.x *= 11.0f / 24.0f;
                    if (line(rd.x,rd.y, rd.z))
                    m_vector1dSpace[x + y*m_x_size + z*m_x_size*m_y_size] = '1';
                }
            }
        }
        const float fov = M_PI / 3;
        float camera_angle = 1.523;
        float theta_camera_angle = 1.523;
        vec3 ro = vec3(1, 1, 1); // camera
        for (size_t j = 0; j < m_y_size; j++){
            for (size_t i = 0; i < m_x_size; i++) { // draw the visibili ty cone
                float angle = camera_angle - fov / 2 + fov * i / float(m_y_size);
                float anglez = theta_camera_angle - fov / 2 + fov * j / float(m_y_size);
                float x, y, z;
                int t = 0;
                for (; t < 300; t++) {
                    x = ro.x + t * cos(angle); // катет x
                    y = ro.y + t * sin(angle); // rfntn y точки в которую упирается чел.
                    z = ro.z + t * cos(anglez);
                    if (m_vector1dSpace[x + y*m_x_size + z*m_x_size*m_y_size] == '1') break;
                }
                m_vector1d[x + y * m_y_size] = (unsigned char)(t%5);
            }
        }    
        return m_vector1d;
    }
};

class printer : private size {
private:
    vector<unsigned char> m_vector1d = vector<unsigned char>(m_x_size*m_y_size);
public:
    printer(vector<unsigned char> vector1d){
        m_vector1d = vector1d;
    }

    void loop2d(){
        while (true){
            for (int y = 0; y < m_y_size; y++){
                for (int x = 0; x < m_x_size; x++){
                    cout << m_vector1d[y+(x*m_x_size)];
                }
                cout << "\n";;
            }
            cout << "\n";
            Sleep(1000);
        }
    }

    void print2d(){
        for (int y = 0; y < m_y_size; y++){
            for (int x = 0; x < m_x_size; x++){
                cout << m_vector1d[y+(x*m_x_size)];
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

int main (){
    canvas canv;

    printer pr(canv.write());
    pr.loop2d();
}