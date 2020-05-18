// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "MathMatrix.h"
#include <iostream>

using namespace std;

int main()
{

    double a[10][10], b[10][10];
    int r1, c1, r2, c2, i, j;
    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    /*while (c1 != r2)
    {
        cout << "Error! column of first matrix not equal to row of second.";
        cout << "Enter rows and columns for first matrix: ";
        cin >> r1 >> c1;
        cout << "Enter rows and columns for second matrix: ";
        cin >> r2 >> c2;
    }*/
    cout << endl << "Enter elements of matrix 1:" << endl;
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c1; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }
    // Storing elements of second matrix.
    cout << endl << "Enter elements of matrix 2:" << endl;
    for (i = 0; i < r2; ++i)
        for (j = 0; j < c2; ++j)
        {
            cout << "Enter element b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }

    //MathFuncs::MyMathFuncs::MatrixMulti(a, b, r1, r2, c1, c2);

    MathMatrix<double> mat1(r1, c1, 1.0);
    MathMatrix<double> mat2(r2, c2, 2.0);
    for (unsigned i = 0; i < mat1.get_rows(); i++) {
        for (unsigned j = 0; j < mat1.get_cols(); j++) {
            mat1(i, j) = a[i][j];
        }
        std::cout << std::endl;
    }
    for (unsigned i = 0; i < mat2.get_rows(); i++) {
        for (unsigned j = 0; j < mat2.get_cols(); j++) {
            mat2(i, j) = b[i][j];
        }
        std::cout << std::endl;
    }

    MathMatrix<double> mat3 = mat1 * mat2;
    MathMatrix<double> mat4 = mat1.transpose();
    std::cout << "Matrix multiplication of Mat 1 and Mat2 is :"<< std::endl;
    for (unsigned i = 0; i < mat3.get_rows(); i++) {
        for (unsigned j = 0; j < mat3.get_cols(); j++) {
            std::cout << mat3(i, j) << '\t';
        }
        std::cout << std::endl;
    }

    std::cout << "Transpose of Mat 1 is :" << std::endl;
    for (unsigned i = 0; i < mat4.get_rows(); i++) {
        for (unsigned j = 0; j < mat4.get_cols(); j++) {
            std::cout << mat4(i, j) << '\t';
        }
        std::cout << std::endl;
    }


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
