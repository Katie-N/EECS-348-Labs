#include <iostream>
#include <fstream>
using namespace std;

// void mulMat(int mat1[][C1], int mat2[][C2])
// {
//     int rslt[R1][C2];

//     cout << "Multiplication of given two matrices is:\n";

//     for (int i = 0; i < R1; i++) {
//         for (int j = 0; j < C2; j++) {
//             rslt[i][j] = 0;

//             for (int k = 0; k < R2; k++) {
//                 rslt[i][j] += mat1[i][k] * mat2[k][j];
//             }

//             cout << rslt[i][j] << "\t";
//         }

//         cout << endl;
//     }
// }


// This function takes in a pointer to a square matrix that has been allocated already.
// It also takes in the size of the matrix so it knows how many times to loop.
// Finally it takes in the address of the file containing the matrix.
// Note that it expects a file that is already opened to the first row and first element of the matrix. (Meaning we have already opened the file and read the size.)
int readMatrix(int* mat, int matrixSize, ifstream &infile) {
    // Loop through rows of the matrix
    for (int i = 0; i < matrixSize; i++) {
        // Loop through columns of the matrix
        for(int j = 0; j < matrixSize; j++) {
            // Read each value into the matrix
            // This is pointer arithmetic to access each element
            // The reason I chose to do this is because we are getting a dynamic matrix size depending on an external file.
            // Because of this, the function cannot take in the actual matrix itself as the dimensions of the matrix must be known at runtime.
            // Therefore I found it simpler to use pointer arithmetic than to use vectors or any other method I saw online.

            // The math works like this:
                // i represents the current row (starting at 0)
                // j represents the current column (starting at 0)
                // matrixSize represents the width and length of the matrix (these are the same because the matrix is square)
                // mat is a pointer meaning it is a memory address. We know that arrays elements are ordered next to each other in computer memory.
                // We also know mat = memory address of the first element in the matrix.
                // mat + 1 = the second element in the matrix. Note that the second element is the second element in the first row. 
                // This clever expression allows us to access mat[i][j] 
            // Since we are trying to assign a value to mat[i][j] we know that we have to dereference the pointer. Otherwise we would be trying to assign a number to another number.
            infile >> *((mat + i * matrixSize) + j);             
        } 
    }
    return 0;
}

// 3. SUM TWO MATRICES FUNCTION
int sumMatrices(int* mat1, int* mat2, int* result, int matrixSize) {
    for(int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            // In execution, this performs
            // result[i][j] = mat1[i][j] + mat2[i][j];
            *((result + i*matrixSize)+j) = *((mat1 + i*matrixSize)+j) + *((mat2 + i*matrixSize)+j);
        }
    }
    return 0;
}

void printMatrix(int* mat, int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            cout << *((mat + i * matrixSize) + j) << "\t";
        }
        cout << "\n";
    }
}

int main() {
    // Open the file containing the matrices
    ifstream infile;
    infile.open("matrix.txt", ifstream::in);

    // Get the size of the matrices by reading the first line of the file.
    // Note that it will read in the value without whitespace to the matrixSize variable.
    int matrixSize;
    infile >> matrixSize;

    // Initialize the matrices with the proper sizes
    int matA[matrixSize][matrixSize];
    int matB[matrixSize][matrixSize];

    // Read in values to the first matrix by passing a pointer to the function
    readMatrix(*matA, matrixSize, infile);
    // Read in values to the second matrix by passing a pointer to the function
    readMatrix(*matB, matrixSize, infile);
    
    // 3. SUM MATRICES
    int sumMat[matrixSize][matrixSize];
    sumMatrices(*matA, *matB, *sumMat, matrixSize);

    cout << "Matrix 1: \n";
    printMatrix(*sumMat, matrixSize);
    // mulMat(mat1, mat2);

    return 0;
}