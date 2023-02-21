#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    int width = 10;
	int height = 10;
	float aspect = (float)width / height;
	float pixelAspect = 11.0f / 24.0f;
	char gradient[] = " .:!/r(l1Z4H9W8$@";
	int gradientSize = size(gradient) - 2;

	char* screen = new char[width * height + 1];
    screen[width * height] = '\0';

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            float x = (float)i / width * 2.0f - 1.0f;
            float y = (float)j / height * 2.0f - 1.0f;
            char pixel = ' ';
            float dist = sqrt(x*x + y*y);
            int color = (int)(1.0f / dist);
            if (color < 0) color = 0;
            else if (color > gradientSize) color = gradientSize;
            pixel = gradient[color];
            screen[i + j * width] = pixel;
            // cout << "i = " << i << " | ";
            // cout << "j = " << j << " | ";
            // cout << "w = " << width << " | ";
            // cout << "sum = " << i+j*width << endl;
            // cout << "x = " << x << " | ";
            // cout << "y = " << y << endl;
             cout << "d = " << dist << " | ";
             cout << "c = " << color << endl;
            
        }
    }

}