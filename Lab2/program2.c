#include <stdio.h>

int main(int argc, char *argv[]) {
    // int score;
    // scanf("Enter a score", &score);
    // while(score >= 2) {

    // }
    if (argc != 2)
    {
        printf("usage: Did you enter a total when you ran the program?\n");
        return 1;
    }

    int total = atoi(argv[1]);

    printf("TD + 2\tTD + 1\tTD\tFG\tS\tto make %d\n", total);

    // We're working with combinations not permutations because we only care about how many of each play was made, not the order that each play was made in.
    // This makes it simpler to calculate.
    // Initialize combos to 0
    int combos = 0;    

    // I found a different but similar enough problem online that dealt with finding the number of combinations of change given a total amount of cents.
    // See https://stackoverflow.com/a/1107115 for reference

    // I had to change a few things from their approach.
    // Obviously I changed all of the variable names to match our football terms rather than coins.
    // Then I changed the values from cents to points
    // Then I had to make another loop because we have 5 plays not 4 coins
        // This part was the hardest because I had to make sure I was following all of the logic correctly when defining the next loop.
        // But I did it and it works.
    // The last thing I had to change was implementing a check. With coins, the remainder can always be made up in pennies.
    // But with football points, not every score is divisible by the smallest unit (that being a safety which is 2 points).
    // Therefore I implemented a check at the innermost loop to make sure that multiplying each count by its respective value produced the desired total.
    // If it does not then we discard this run and continue.
    // This is not the most optimized solution but it works.
    
    // We could make a recursive function to handle this.
    // However, my brain tends to like iterative loops more.
    // So I will approach it with nested for loops.

    // Each loop initializes a count for one of the plays.
    // We start with the largest point value on the outside (because we can make the fewest combinations with the largest values)
    // Then we work our way in to the smallest point value.
    // Each loop will continue until the count of their plays surpasses the number of possible plays left with the remaining points
    for (int td2 = 0; td2 <= total / 8; td2++) {
        int total_minus_td2 = total - td2 * 8;
        for (int td1 = 0; td1 <= total_minus_td2 / 7; td1++) {
            int total_minus_td1 = total_minus_td2 - td1 * 7;
            for (int td = 0; td <= total_minus_td1 / 6; td++) {
                int total_minus_td = total_minus_td1 - td * 6;
                for (int fg = 0; fg <= total_minus_td / 3; fg++) {
                    int total_minus_fg = total_minus_td - fg * 3;
                    // We don't need a loop for determining the number of safety plays
                    // We just divide the remaining points by the point value of a safety (2)
                    int s = total_minus_fg / 2;
                    if (td2*8 + td1*7 + td*6 + fg*3 + s*2 == total) {
                        // Print this combination
                        printf("%d\t%d\t%d\t%d\t%d\n", td2, td1, td, fg, s);
                        combos++;
                    }
                }
            }
        }
    }

    printf("There are %d possible ways to score %d points\n", combos, total);

    return 0;
}