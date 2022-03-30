#include "Matrix.h"
#include <iostream>
#include "assert.h"

Matrix::Matrix(int nRows, int nColumns){
    assert(nRows > 0 && nColumns > 0);
    rows = nRows;
    columns = nColumns;

    double** nullMatrix = createMatrix();
    for(int i = 0; i < rows; i++){
        nullMatrix[i] = new double[columns];
        for(int j = 0; j < columns; j++){
            nullMatrix[i][j] = 0;
        }
    }
    matrix = nullMatrix;
}

Matrix::Matrix(int nRows){
    assert(nRows > 0);
    rows = nRows;
    columns = nRows;

    double** idMatrix = createMatrix();
    for(int i = 0; i < rows; i++){
        idMatrix[i] = new double[columns];
        for(int j = 0; j < columns; j++){
            if(j == i){
                idMatrix[i][j] = 1;
            }
            else{
                idMatrix[i][j] = 0;
            }
        }
    }
    matrix = idMatrix;
}

Matrix::~Matrix(){
    for( int i = 0 ; i < rows ; i++ ) {
    delete [] matrix[i];
}
    delete [] matrix;
}

double** Matrix::createMatrix(){
    double** trashMatrix{new double*[rows]};
    for(int i = 0; i < rows; i++){
        trashMatrix[i] = new double[columns];
    }
    return trashMatrix;
}

double Matrix::get(int rowInd, int columnInd) const{
    return matrix[rowInd][columnInd];
}

void Matrix::set(int rowInd, int columnInd, double value){
    matrix[rowInd][columnInd] = value;
}

int Matrix::getColumns() const{
    return columns;
}

int Matrix::getRows() const{
    return rows;
}

std::ostream& operator<<(std::ostream& os, Matrix& m){
    for(int i = 0; i < m.getRows(); i++){
        for(int j = 0; j < m.getColumns(); j++){
            os << m.matrix[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

Matrix::Matrix(const Matrix& m){
    rows = m.rows;
    columns = m.columns;
    double** newMatrix = createMatrix();
    for(int i = 0; i < rows; i++){
        newMatrix[i] = new double[columns];
        for(int j = 0; j < columns; j++){
            double value = m.get(i, j);
            newMatrix[i][j] = value;
        }
    }
    matrix = newMatrix;
}

Matrix Matrix::operator=(Matrix m){
    std::swap(matrix, m.matrix);
    rows = m.rows;
    columns = m.columns;
    return *this;
}

Matrix Matrix::operator+=(const Matrix m){
    if(m.rows != rows || m.columns != columns){
        std::cout << "Matrices do not have same dimenions.\n";
        std::cout << "Rows:" << rows << ", " << m.rows << "\n";
        std::cout << "Columns:" << columns << ", " << m.columns << "\n";
    }
    else{
        for (int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                this->matrix[i][j] += m.matrix[i][j];
            }
        }      
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix m){
    Matrix mat2 = *this;
    mat2 += m;
    return mat2;
}