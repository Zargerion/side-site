#include <iostream>
#include <vector>
#include <complex>

using namespace std;

float normPlusMinusOne(float input, float min, float max)
{
    float average      = (min + max) / 2;
    float range        = (max - min) / 2;
    float normalized_x = (input - average) / range;
    return normalized_x;
}

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

struct Spherical {
  float r, theta, phi;
  Spherical(float r_, float theta_, float phi_) {
    r = r_;
    theta = theta_;
    phi = phi_;
  }
};

Spherical spherical(float x, float y, float z) {
  float r = sqrt(x*x + y*y + z*z);
  float theta = atan2( sqrt(x*x+y*y), z);
  float phi = atan2(y, x);
  return Spherical(r, theta, phi);
}

int main()
{
    int size = 100;
    float pixel_aspect_ratio = 11.0f / 24.0f; //соотношение

    vector<vector<vector<unsigned char>>> 
    vec3d(size, vector<vector<unsigned char>>
    (size, vector<unsigned char>(size, '0')));
    const int reducedsize = size;
    vector<vector<unsigned char>> 
    vec2d(size, vector<unsigned char>(size));
    vector<unsigned char> vec1d(size*size);
    for (int z = 0; z < size; z++)
    {
        for (int y = 0; y < size; y++)
        { 
            bool edge = false;
            for (int x = 0; x < size; x++)
            {
                //if (((x - size / 2) * (x - size / 2) + (y - size / 2) * 
                //(y - size / 2) + (z - size / 2) * (z - size / 2) <= reducedsize * 20))
                //{
                //    vec3d[z][y][x] = '1';
                //}

               // complex<double> zcomplex(0, 0);
			   // int i = 0;
               // int s = 30;
			   // while (i < 10 && abs(zcomplex) < 2)
			   // {
			   // 	zcomplex = pow(zcomplex, 2) + 
               //     complex<double>(1.0 * (x - size / 2) / s, 1.0 * (y - size / 2) / s);                  
			   // 	++i;
			   // }
			   // if (abs(zcomplex) >= 2)
			   // {
               // 
			   // }
               // if (i >= 10)
               // {
               //     if (!edge)
               //     {
               //         vec3d[z][y][x] = '1';
               //     }
               //     
               // }      
                //float normX = normPlusMinusOne(x, 0, size);
                //float normY = normPlusMinusOne(y, 0, size/2);
                //float normZ = normPlusMinusOne(z, 0, size);
                float a = 2;
                float normX = (((float)x / size * 2.0f) - 1.0f) ;
                float normY = (((float)y / size * 2.0f) - 1.0f) ;
                float normZ = (((float)z / size * 2.0f) - 1.0f) ;

                
                vec3 zeta(0,0,0);
            

                //float r = sqrt(normX*normX + normY*normY + normZ*normZ) * 2.5;
                //float angleByX = acos(normZ/r);
                //float angleByZ = atan(normY/normX);

                int n = 2;
                int maxiterations = 10;
                int iteration = 0;

                while (true)
			    {
                    Spherical c = spherical(zeta.x, zeta.y, zeta.z);
			    	float newx = pow(c.r, n) * sin(c.theta*n) * cos(c.phi*n);
                    float newy = pow(c.r, n) * sin(c.theta*n) * sin(c.phi*n);
                    float newz = pow(c.r, n) * cos(c.theta*n);
                    zeta.x = newx + normX;
                    zeta.y = newy + normY;
                    zeta.z = newz + normZ;
                    iteration++;
                    if (c.r > 2)
                    {
                        break;
                    }
                    if (iteration >= maxiterations)
                    { 
                        vec3d[z][y][x] = '1';
                        break;
                    }    
                }
			    

            }
        }
    }

    int i = 0;
    for (int z = 0; z < size; z++)
    {
        for (int y = 0; y < size; y++)
        {
            for (int x = 0; x < size; x++)
            {
                if (z == 0)
                {
                    for (int step = 0; step < size; step++)
                    {

                        if ( step < 3 ) 
                        { 
                            vec1d[i] = '1';
                        } 
                        else if ( step < 6 )
                        { 
                            vec1d[i] = '2';
                        } 
                        else if ( step < 9 )
                        { 
                            vec1d[i] = '3';
                        } 
                        else if ( step < 12 )
                        { 
                            vec1d[i] = '4';
                        } 
                        else if ( step < 15 )
                        { 
                            vec1d[i] = '5';
                        }
                        else if ( step < 18 )
                        { 
                            vec1d[i] = '6';
                        } 
                        else if ( step < 21 )
                        { 
                            vec1d[i] = '7';
                        } 
                        else if ( step < 24 )
                        { 
                            vec1d[i] = '8';
                        } 
                        else if ( step < 27 )
                        { 
                            vec1d[i] = '9';
                        }
                        else
                        { 
                            vec1d[i] = '#';
                        } 
                        if(vec3d[z+step][y][x] == '1') { break; }
                    }
                    i++;
                }
            }
        }
    }

    int liststep = 0;
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            vec2d[y][x] = vec1d[liststep];
            liststep++;
        }
    }

    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            cout << vec2d[y][x];
        }
        cout << endl;
    }

    
}