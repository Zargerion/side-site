#include <iostream>
#include <vector>

class Matrix {
public:
    Matrix(int rows, int columns) : rows(rows), columns(columns), data(rows * columns) {}

    int& operator()(int row, int column) {
        return data[row * columns + column];
    }

    int operator()(int row, int column) const {
        return data[row * columns + column];
    }

    int getRows() const { return rows; }
    int getColumns() const { return columns; }

private:
    int rows, columns;
    std::vector<int> data;
};

class Vector {
public:
    Vector(int size) : size(size), data(size) {}

    double& operator[](int index) {
        return data[index];
    }

    double operator[](int index) const {
        return data[index];
    }

    int getSize() const { return size; }

private:
    int size;
    std::vector<double> data;
};

Vector operator*(const Matrix& matrix, const Vector& vector) {
    int rows = matrix.getRows();
    int columns = matrix.getColumns();

    if (columns != vector.getSize()) {
        throw "Matrix and vector sizes do not match";
    }

    Vector result(rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i] += matrix(i, j) * vector[j];
        }
    }

    return result;
}