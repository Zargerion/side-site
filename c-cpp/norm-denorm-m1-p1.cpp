#include <iostream>

float normalize(float value, float min, float max) {
    return 2 * (value - min) / (max - min) - 1;
}

float denormalize(float value, float min, float max) {
    return (value + 1) * (max - min) / 2 + min;
}

int main() {
    float value = 11.0f;
    std::cout << value << std::endl;
    float min = 0.0f;
    float max = 20.0f;
    value = normalize(value, min, max);
    std::cout << value << std::endl;
    std::cout << denormalize(value, min, max) << std::endl;

    return 0;
}