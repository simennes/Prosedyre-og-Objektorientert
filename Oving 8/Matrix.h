#pragma once
#include <iostream>

class Matrix{
    private:
        int rows;
        int columns;
        double** createMatrix();
    public:
        double** matrix;
        Matrix(int nRows, int nColumns);
        explicit Matrix(int nRows);
        Matrix(const Matrix& m);
        ~Matrix();

        double get(int row, int col) const;
        void set(int row, int col, double value);
        int getRows() const;
        int getColumns() const;
        friend std::ostream& operator<<(std::ostream& os, Matrix& m);
        Matrix operator=(Matrix m);
        Matrix operator+=(const Matrix m);
        Matrix operator+(const Matrix m);
};