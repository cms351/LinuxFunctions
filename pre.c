#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    

    // declare 2d array. 10 arrays of 50 character elements.
    // in other words, an array of 10 strings with a 50 character max
    char students[10][20];
    // declare gpa and a counter variable
    double gpa; 
    int counter = 0; 


    // for loop for inputting student names + gpas
    int i;
    for (i = 0; i < 10; i++) {

        scanf("%s %lf", students[counter], &gpa);

        if (gpa > 3) {
            counter++;
        }

    }

    // for loop for printing students' names
    for (i = 0; i < counter; i++) {

        printf("%s", students[i]);
        // need this if statement to prevent a bunch of empty lines from printing at the end of the program. 
        // Effectively: "if the first character of the string is the null character, break the loop"
       if (students[i+1][0] == '\0') {
           break; 
       }

       printf("\n");
    }
 
 
 
    return 0;

}