#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {


    // array for students names
    char tempArray[10][50];

    int i;
    for (i = 0; i < 10; i++){
        scanf("%s", tempArray[i]); 
    }

    char students[10][50]; 
    int counter = 0; 

    for (i = 0; i < 10; i++) {
        if (tempArray[i][0] != '\0' || tempArray[i][0] != ' ' || tempArray[i][0] != '\n') {
            strcpy(students[counter], tempArray[i]);
            counter++; 
        }
    }

    // temp variable to help with sorting
    char tempString[50]; 


    // loop for sorting array
    // bubble sort
    int j;
    for (i = 0; i < counter; i++) {
        for (j = 0; j < (counter - i); j++) {
            // if the first letter of string is closer to front of alphabet than the 
            // next string, swap the strings. 
            if (students[j][0] > students[j+1][0]) {
                // copy first string into temp string
                strcpy(tempString, students[j]);
                // copy second string into first string
                strcpy(students[j], students[j+1]);
                // copy temp string into second string
                strcpy(students[j+1], tempString); 
            }

            // catch if the next string element is null, and if so, break the loop
            if (students[j+2][0] == '\0') {
                break;
            }
        }
    }

    
    int k; 
    for (k = 0; k < 10; k++) {

        // if first character of string is null, break loop
        if (students[k][0] == '\0') {
            // printf("%c", '\n'); 
            break; 
        }
        else if (students[k][0] == '\n') {
            continue;
        }
        else {
            printf("%s", students[k]); 
            printf("%c", '\n');
        }
        
    }

    return 0;

}