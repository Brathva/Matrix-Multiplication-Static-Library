# Matrix-Multiplication-and-Transposition-static-Library
Matrix Multiplication and Transposition high-performance, portable linear algebra library using only standard libraries. Program is implemented in standard C++11. 

Compiler command used to compile source file: g++ main.cpp -std=c++11 -lthread


#Steps:

1) Compile the Main.cpp file under MyExecRefsLib folder using g++ compiler

2) Provide number of rows and columns and values for Matrix 1 and Matrix 2.

3) Result for the matrix multiplication and Transpose of a matrix will be obtained.



##Details:

	1) Main.cpp is created such that it asks for number of rows and columns for Matrix 1 and Matrix 2 and then the values.

	2) Rule for Matrix Multiplication can be handled in Main.cpp but to showcase the exception handling in library file
for the Rule, I have opted out. (Rule - Number of columns in Matrix 1 and number of rows in Matrix 2 should be same)

	3) Transpose of a matrix has been not a seperate Input/Output, instead the matrix 1 will act as a matrix to transpose.

	4) Used Template to do multiple operations on input matrices.

	5) Function declaration are done in .h file and definitions are done in .cpp file


 
