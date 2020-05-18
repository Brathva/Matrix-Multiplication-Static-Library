#pragma once
#ifndef __QS_MATRIX_H
#define __QS_MATRIX_H

#include <vector>

template <typename T> class MathMatrix {
private:
    std::vector<std::vector<T> > mat;
    unsigned rows;
    unsigned cols;

public:
    MathMatrix(unsigned _rows, unsigned _cols, const T& _initial);
    MathMatrix(const MathMatrix<T>& rhs);
    virtual ~MathMatrix();

    // Operator overloading, for "standard" mathematical matrix operations                                                                                                                                                          
    MathMatrix<T>& operator=(const MathMatrix<T>& rhs);

    // Matrix mathematical operations                                                                                                                                                                                               

    MathMatrix<T> operator*(const MathMatrix<T>& rhs);
    MathMatrix<T> transpose();


    // Access the individual elements                                                                                                                                                                                               
    T& operator()(const unsigned& row, const unsigned& col);
    const T& operator()(const unsigned& row, const unsigned& col) const;

    // Access the row and column sizes                                                                                                                                                                                              
    unsigned get_rows() const;
    unsigned get_cols() const;

};
#include "MathMatrix.cpp"
#endif