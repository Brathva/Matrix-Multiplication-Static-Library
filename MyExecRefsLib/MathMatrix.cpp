#pragma once

#include "pch.h"
#ifndef __QS_MATRIX_CPP
#define __QS_MATRIX_CPP
#include "MathMatrix.h"
#include<stdexcept>
#include<iostream>
using namespace std;

// Parameter Constructor                                                                                                                                                      
template <typename T>
MathMatrix<T>::MathMatrix(unsigned _rows, unsigned _cols, const T& _initial) {
    mat.resize(_rows);
    for (unsigned i = 0; i < mat.size(); i++) {
        mat[i].resize(_cols, _initial);
    }
    rows = _rows;
    cols = _cols;
}

// Copy Constructor                                                                                                                                                           
template <typename T>
MathMatrix<T>::MathMatrix(const MathMatrix<T>& rhs) {
    mat = rhs.mat;
    rows = rhs.get_rows();
    cols = rhs.get_cols();
}

// (Virtual) Destructor                                                                                                                                                       
template <typename T>
MathMatrix<T>::~MathMatrix() {}

// Assignment Operator                                                                                                                                                        
template <typename T>
MathMatrix<T>& MathMatrix<T>::operator=(const MathMatrix<T>& rhs) {
    if (&rhs == this)
        return *this;

    unsigned new_rows = rhs.get_rows();
    unsigned new_cols = rhs.get_cols();

    mat.resize(new_rows);
    for (unsigned i = 0; i < mat.size(); i++) {
        mat[i].resize(new_cols);
    }

    for (unsigned i = 0; i < new_rows; i++) {
        for (unsigned j = 0; j < new_cols; j++) {
            mat[i][j] = rhs(i, j);
        }
    }
    rows = new_rows;
    cols = new_cols;

    return *this;
}

// Left multiplication of this matrix and another                                                                                                                              
template <typename T>
MathMatrix<T> MathMatrix<T>::operator*(const MathMatrix<T>& rhs) {
    
    unsigned rows_mat1 = this->mat.size();
    unsigned cols_mat1 = this->mat[0].size();
    unsigned rows_mat2 = rhs.get_rows();
    unsigned cols_mat2 = rhs.get_cols();
      
    MathMatrix result(rows_mat1, cols_mat2, 0.0);
    try {
        if (cols_mat1 == rows_mat2)
        {
            for (unsigned i = 0; i < rows_mat1; i++) {
                for (unsigned j = 0; j < cols_mat2; j++) {
                    for (unsigned k = 0; k < cols_mat1; k++) {
                        result(i, j) += this->mat[i][k] * rhs(k, j);
                    }
                }
            }
        }
        else
        {
            throw std::invalid_argument("Number of rows in matrix 1 and Number of columns in matrix 2 should be same");
        }
    }
    catch (const std::invalid_argument & e) {
        cout << "Exception: Number of rows in matrix 1 and Number of columns in matrix 2 should be same" <<endl;
        exit(0);
    }
    return result;
}

// Calculate a transpose of this matrix                                                                                                                                       
template <typename T>
MathMatrix<T> MathMatrix<T>::transpose() {
    MathMatrix result(cols, rows, 0.0);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(j, i) = this->mat[i][j];
        }
    }

    return result;
}

// Access the individual elements                                                                                                                                             
template <typename T>
T& MathMatrix<T>::operator()(const unsigned& row, const unsigned& col) {
    return this->mat[row][col];
}

// Access the individual elements (const)                                                                                                                                     
template <typename T>
const T& MathMatrix<T>::operator()(const unsigned& row, const unsigned& col) const {
    return this->mat[row][col];
}

// Get the number of rows of the matrix                                                                                                                                       
template <typename T>
unsigned MathMatrix<T>::get_rows() const {
    return this->rows;
}

// Get the number of columns of the matrix                                                                                                                                    
template <typename T>
unsigned MathMatrix<T>::get_cols() const {
    return this->cols;
}
#endif