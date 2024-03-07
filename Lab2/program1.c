#include <stdio.h>
// Strings in C are really arrays of characters. So an array of characters is made as an array of arrays of characters
char MONTHS[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
// The array will contain 12 floating point values that represent the monthly sales reports
float MONTHLYREPORT[12];
float SORTEDMONTHLYREPORT[12];

// char SORTEDMONTHS[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int readInputs() {
    FILE *inputFile; // File pointer
    inputFile = fopen("input.txt", "r");

    // Open the input file in read mode because we don't need to edit it, just read the data

    // Let the user know if the input file is missing
    if(inputFile == NULL) {
        printf("Unable to open the file. Is it named 'input.txt' in the same directory as this program?");
    }

    // Read the input file into the array
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
float getAverage(float arr[], int length) {
    float total = 0;
    for (int i = 0; i < length; i++) {        
        total += arr[i];
    }
    return total / (float) length; // We need to do floating point division because we want to know the average cents too
}

int getIndexInArr(float value) {
    int index = 0;
    for (int i = 0; i < 12; i++) {
        if (value == MONTHLYREPORT[i]) {
            return i;
        }
    }
    return -1;
}

int createDescendingOrder() {
    // int indices[] = {0,1,2,3,4,5,6,7,8,9,10,11};
    // copying elements from one array to another 
    for (int i = 0; i < 12; i++) { 
        SORTEDMONTHLYREPORT[i] = MONTHLYREPORT[i];
    } 

    // int sortedIndices[12];
    float temp = 0;
    char tempMonth[1][10];
    // iterates the array elements 
    for (int i = 0; i < 12; i++) { 
        
        // iterates the array elements from index 1 
        for (int j = i + 1; j < 12; j++) { 
            
            // compare each element in the array
            if (SORTEDMONTHLYREPORT[i] < SORTEDMONTHLYREPORT[j]) { 
                
                temp = SORTEDMONTHLYREPORT[i]; 
                SORTEDMONTHLYREPORT[i] = SORTEDMONTHLYREPORT[j]; 
                SORTEDMONTHLYREPORT[j] = temp;
            } 
        } 
    } 
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
    
    // Print each month's revenue
    for (int i = 0; i < 12; i++) {
        // Print each month and the sales amount next to it
        // -12 in the format specifier is to left align the strings so they all line up correctly.
        // "\t" is not helpful because the different lengths of the month strings leads to the sales numbers moving to two different indentations.
        printf("%-12s$%-12.2f\n", MONTHS[i], MONTHLYREPORT[i]);
    }

    // Sales Summary
    printf("\nSales Summary:\n");
    int indexOfMinVal = getMinValIndex(MONTHLYREPORT);
    printf("Minimum Sales:\t$%.2f\t(%s)\n", MONTHLYREPORT[indexOfMinVal], MONTHS[indexOfMinVal]);

    int indexOfMaxVal = getMaxValIndex(MONTHLYREPORT);
    printf("Maximum Sales:\t$%.2f\t(%s)\n", MONTHLYREPORT[indexOfMaxVal], MONTHS[indexOfMaxVal]);

    float averageSales = getAverage(MONTHLYREPORT, 12);
    printf("Average Sales:\t$%.2f\n", averageSales);
    
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i < 7; i++) {
        // Print out the moving average for 6 month intervals shifting by 1 month each time
        // Rather than creating an element-wise copy of MONTHLYREPORT for all 7 subsets,
        // we can use pointer arithmetic to intelligently shift the starting memory address of MONTHLYREPORT.
        // Then we tell the getAverage function to only take the first 6 values from the array.
        printf("%-12s-\t%-12s%.2f\n", MONTHS[i], MONTHS[i+5], getAverage((MONTHLYREPORT + i), 6));
    }

    // Highest to Lowest
    printf("\nSales Report (Highest to Lowest):\n");
    // Call the helper function that loops through the monthly report and sorts it into descending order
    createDescendingOrder();
    // Print each month's revenue
    for (int i = 0; i < 12; i++) {
        // Print each month and the sales amount next to it
        int originalIndex = getIndexInArr(SORTEDMONTHLYREPORT[i]);
        printf("%-12s$%-12.2f\n", MONTHS[originalIndex], SORTEDMONTHLYREPORT[i]);
    }
    
    return 0;
}

