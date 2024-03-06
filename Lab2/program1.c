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

// This function takes an array of floats, loops through them comparing each value, and then returns the index of the smallest value in the array
int getMinValIndex(float arr[]) {
    int min = 0;
    for (int i = 0; i < 12; i++) {
        if (arr[i] < arr[min]) {
            min = i;
        }
    }
    return min;
}

// This function takes an array of floats, loops through them comparing each value, and then returns the index of the smallest value in the array
int getMaxValIndex(float arr[]) {
    int max = 0;
    for (int i = 0; i < 12; i++) {
        if (arr[i] > arr[max]) {
            max = i;
        }
    }
    return max;
}

// This function takes an array of floats, loops through them comparing each value, and then returns the index of the smallest value in the array
float getAverage(float arr[]) {
    float total = 0;
    for (int i = 0; i < 12; i++) {        
        total += arr[i];
    }
    return total / 12.0; // We need to do floating point division because we want to know the average cents too
}


int main() {
    // This reads in the numbers from the input file to the global array MONTHLYREPORT
    readInputs();

    printf("Monthly Sales Report for 2023:\n");
    // I know I can left align the text when I can use format specifier.
    // I only know how to use format specifiers with a variable.
    // So I will make a variable to contain the "Month" string.
    char tempMonthArr[10] = {"Month"};
    printf("%-12sSales\n", tempMonthArr);
    // Strings in C are really arrays of characters. So an array of characters is made as an array of arrays of characters
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Print each month's revenue
    for (int i = 0; i < 12; i++) {
        // Print each month and the sales amount next to it
        // -12 in the format specifier is to left align the strings so they all line up correctly.
        // "\t" is not helpful because the different lengths of the month strings leads to the sales numbers moving to two different indentations.
        printf("%-12s$%-12.2f\n", months[i], MONTHLYREPORT[i]);
    }

    // Sales Summary
    printf("\nSales Summary:\n");
    int indexOfMinVal = getMinValIndex(MONTHLYREPORT);
    printf("Minimum Sales:\t%.2f\t(%s)\n", MONTHLYREPORT[indexOfMinVal], months[indexOfMinVal]);

    int indexOfMaxVal = getMaxValIndex(MONTHLYREPORT);
    printf("Maximum Sales:\t%.2f\t(%s)\n", MONTHLYREPORT[indexOfMaxVal], months[indexOfMaxVal]);

    float averageSales = getAverage(MONTHLYREPORT);
    printf("Average Sales:\t%.2f\n", averageSales);
    
    return 0;
}

