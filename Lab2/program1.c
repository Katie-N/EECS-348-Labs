#include <stdio.h>

float MONTHLYREPORT[12]; // The array will contain 12 floating point values that represent the monthly sales reports

int readInputs() {
    FILE *inputFile; // File pointer
    inputFile = fopen("input.txt", "r");

    // Read the input file into the array

    // Open the input file in read mode because we don't need to edit it, just read the data

    // Let the user know if the input file is missing
    if(inputFile == NULL) {
        printf("Unable to open the file. Is it named 'input.txt' in the same directory as this program?");
    }

    // There are 12 numbers so we will loop 12 times
    for (int i = 0; i < 12; i++) {
        fscanf(inputFile, "%f", &MONTHLYREPORT[i]); // Read in each line as a float to the global array
        // printf("%.2f\n", MONTHLYREPORT[i]);
    }

    // Close the file
    fclose(inputFile); 
    return 0;
}

int main() {
    // This reads in the numbers from the input file to the global array MONTHLYREPORT
    readInputs();

    printf("Monthly Sales Report for 2023:\n");
    // I know I can left align the text when I can use format identifiers.
    // I only know how to use format identifiers with a variable.
    // So I will make a variable to contain the "Month" string.
    char tempMonthArr[10] = {"Month"};
    printf("%-12sSales\n", tempMonthArr);
    // Strings in C are really arrays of characters. So an array of characters is made as an array of arrays of characters
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    for (int i = 0; i < 12; i++) {
        // Print each month and the sales amount next to it
        // -12 in the format identifier is to left align the strings so they all line up correctly.
        // "/t" is not helpful because the different lengths of the month strings leads to the sales numbers moving to two different indentations.
        printf("%-12s$%-12.2f\n", months[i], MONTHLYREPORT[i]);
    }
    
    return 0;
}

