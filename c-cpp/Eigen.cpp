#include <iostream>
#include "C:\dev\cpplibs\eigen-3.4.0\Eigen\Dense"

# define M_PI           3.14159265358979323846

double normalize(double value, double min, double max) {
    return 2 * (value - min) / (max - min) - 1;
}
double denormalize(double value, double min, double max) {
    return (value + 1) * (max - min) / 2 + min;
}
Eigen::Matrix<double, 1, 3> normalizeVec3(Eigen::Matrix<double, 1, 3> value, double min, double max) {

    for (size_t i = 0; i < 3; i++)
    {
       value(i) = normalize(value(i), min, max);
    }
    
    return value;
}
Eigen::Matrix<double, 1, 3> denormalizeVec3(Eigen::Matrix<double, 1, 3> value, double min, double max) {
    
    for (size_t i = 0; i < 3; i++)
    {
       value(i) = denormalize(value(i), min, max);
    }
    return value;
}

int main(){

    Eigen::Matrix<double, 3, 3> BaseMatrix;
        BaseMatrix << 1, 0, 0,
                    0, 1, 0,
                    0, 0, 1;

    Eigen::Matrix<double, 3, 3> RotationMartix;
        RotationMartix << cos(45), sin(45), 0,
            -sin(45), cos(45), 0,
            0, 0, 1;

    Eigen::Matrix<double, 1, 3> vec1;
                vec1 << 0, 50, 1;
                BaseMatrix *= RotationMartix;
                vec1 *= BaseMatrix;
                

    //std::cout << vec1 << std::endl;

    Eigen::Matrix3f m1;

    Eigen::Matrix<double, 1, 3> vec;
        vec << 10, 20, 1;

    double value = 10.0f;
    //std::cout << vec << std::endl;
    double min = 0.0f;
    double max = 20.0f;
    vec = normalizeVec3(vec, min, max);
    //std::cout << vec << std::endl;
    vec1 *= BaseMatrix;
    //std::cout << vec << std::endl;
    vec = denormalizeVec3(vec, min, max);
    //std::cout << vec << std::endl;

    vec << 10, 20, 1;
    //std::cout << vec << std::endl;
    //vec << 1, 2, 1;
    //std::cout << vec << std::endl;

    double right = 0;
    double left = 20;
    double top = 0;
    double bottom = 20;
    double near = -1;
    double far = 1;

    Eigen::Matrix<double, 4, 4> ViewPortMatrixOrto;
        ViewPortMatrixOrto << 2.0 / (right - left), 0.0, 0.0, 0.0,
        0.0, 2.0 / (top - bottom), 0.0, 0.0,
        0.0, 0.0, -2.0 / (far - near), 0.0,
        -(right + left) / (right - left), -(top + bottom) / (top - bottom), -(far + near) / (far - near), 1.0;
    
    Eigen::Matrix<double, 3, 3> OtroProjPortMatrix3;
        OtroProjPortMatrix3 << (2.0 / (right - left)), 0, 0,
        0, (2.0 / (top - bottom)), 0,
        (-(right + left) / (right - left)), (-(top + bottom) / (top - bottom)), 1;

    vec = vec * OtroProjPortMatrix3;
   

    //vec = vec * OtroProjPortMatrix3;
    //std::cout << vec << std::endl;

    //vec << 10, 20, 1;
    //std::cout << vec << std::endl;
    double width = 20, height = 20;
    
    Eigen::Matrix<double, 3, 3> DeViewPortMatrix3;
    DeViewPortMatrix3 << width/2, 0, 0,
                        0, -height/2, 0,
                        width/2, height/2, 1;

    vec = vec * DeViewPortMatrix3;
    //std::cout << vec << std::endl;

    Eigen::Matrix<double, 1, 4> vec4;
    vec4 << 10, 20, 2,  1;
    //std::cout << vec4 << std::endl;

    double aspect = 1;
    double fovy = 45;
    bottom = near * tan(fovy * M_PI / 360.0);
    top = -bottom;
    left = top * aspect;
    right = bottom * aspect;

    Eigen::Matrix<double, 4, 4> FrustrumMatrix4;
    FrustrumMatrix4 << (2 * near) / (right - left), 0, 0, 0,
                        0, (2 * near) / (top - bottom), 0, 0, 
                        (right + left) / (right - left), (top + bottom) / (top - bottom), -(far + near) / (far - near), -1.0,
                        0, 0, (-(2 * far * near) / (far - near)), 0;

    Eigen::Matrix<double, 4, 4> PerspectiveMatrix4;
    PerspectiveMatrix4 << (2 * near) / (right - left), 0, 0, 0,
                            0, (2 * near) / (bottom - top), 0, 0,
                            0, 0, -(far + near) / (far - near), -1,
                            0, 0, -(2 * far * near) / (far - near), 0;

    vec4 *= FrustrumMatrix4;
    //std::cout << vec4 << std::endl;
    vec4 *= PerspectiveMatrix4;
    //std::cout << vec4 << std::endl;
    
    vec4 << 10, 20, 2,  1;;
    //std::cout << vec4 << std::endl;
    Eigen::Matrix<double, 4, 4> SimplePerspectiveMatrix4;
    SimplePerspectiveMatrix4 << 1/(aspect * tan(fovy/2)), 0, 0, 0,
                                0, 1/(tan(fovy/2)), 0, 0,
                                0, 0, -((far+near)/(far-near)), ((2*far*near)/(far-near)),
                                0, 0, -1, 0;
    vec4 *= SimplePerspectiveMatrix4;
    vec4 << 10, 20, 0,  1;;
    std::cout << vec4 << std::endl;
    vec4 *= ViewPortMatrixOrto;
    std::cout << vec4 << std::endl;
}