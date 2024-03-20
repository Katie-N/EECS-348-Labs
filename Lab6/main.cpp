#include <iostream> 
#include <fstream>
#include <vector>
#include <typeinfo>
using namespace std;

const int matrixWidth = 3;
int MATRIX[matrixWidth][matrixWidth] = 
   {{0,0,0}, 
    {0,1,0}, 
    {1,0,0}};
int MATRIX2[matrixWidth][matrixWidth] = 
   {{1,2,3}, 
    {4,5,6}, 
    {0,0,0}};

// The easiest way to handle a dynamically sized array is through the std::vector type.
// It Functions as an array however it allows us to resize it (something that regular arrays do not allow)

// This function fulfills requirement 1 to read in values from a file to a matrix.
// We first accept the file object. We also accept the address of the 2 dimensional array we need to read into.
int readMatrices(ifstream &myInputFile, vector<vector<int>> &array) {
    // If the file is not already opened,
    // we need to read the first line to get the matrix size
    int matrixSize;
    // This lets us read in the value without whitespace to the matrixSize variable
    myInputFile >> matrixSize;
    // Now that we know how big the matrix should be, we can resize the vector.
    // This is the reason I chose to use the vector type rather than the default list type.
    // With vectors I can resize them based on external input.
    // The rows should be just the matrixSize and the columns should be another vector with matrixSize allocated
    array.resize(matrixSize, vector<int>(matrixSize));

    // Loop through the rows
    for(int i = 0; i < matrixSize; i++){
        // Loop through the columns
        for (int j=0; j<matrixSize; j++) {
            // Read in the element to the 2D array at the current position
            myInputFile >> array[i][j];
        }
    }

    return matrixSize;
}

int printMatrix(int matrixSize, vector<vector<int>> &array) {
    for(int i = 0; i < matrixSize; i++){
        for (int j=0; j<matrixSize; j++) {
            cout << array[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}

int addMatrices(int matrixSize, vector<vector<int>> &matrix1, vector<vector<int>> &matrix2, ) {
    cout << "Adding: " << matrixSize << "\n";
    for(int i = 0; i < matrixSize; i++){
        for (int j=0; j<matrixSize; j++) {
            int id = matrix1[i][j] + matrix2[i][j];
            cout << id;
            // matrix1[i][j] + matrix2[i][j] >> result[i][j];
        }
        cout << "\n";
    }
    return 0;
}

int main() {
    // fstream file ("matrix.txt", ios::in | ios::binary)
    // char data[100];
    // file.read(data, sizeof(data));
    // file.close();

    // Open up the file as an ifstream object. I called it "infile" because it is the input file.
    ifstream infile;
    infile.open("matrix.txt", ifstream::in);
    

    // string myString;
    // // getline(infile, myString); // This gets the first line
    // string rowString;

    // getline(infile, rowString);

    // int stringLength = rowString.length();

    // for(int i = 0; i < stringLength; i++) {
    //     cout << rowString[i];
    //     // while(rowString[i] != " ") {
    //     //     cout << rowString[i];
    //     //     i++;
    //     // }
    //     cout << "\n";
    // }
    // // cout << myString;
    // // while (!infile.eof()) {
    // //     infile >> myString;
    // //     cout << myString.data() << endl;

    // // }  
    // infile.close();

    vector<vector<int>> array;
    int currentSize = readMatrices(infile, array);
    printMatrix(currentSize, array);

    vector<vector<int>> array2;
    vector<vector<int>> sumArray;
    addMatrices(currentSize, array, array2, sumArray);
    // printMatrix(currentSize, sumArray);

    return 0;
}